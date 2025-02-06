#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int shortest(int n,int m,int start_y,int start_x,int end_y,int end_x,vector<string> maze)
{
        int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
        int dis_from_start[n][m];
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
                        dis_from_start[i][j] = 12345;
                }
        }
        vector<vector<int>> start_list = {{start_y,start_x}};
        dis_from_start[start_y][start_x] = 1;
        while(!start_list.empty())
        {
                int todos = start_list.size();
                int check_y = start_list[todos-1][0];
                int check_x = start_list[todos-1][1];
                start_list.pop_back();
                for(int i=0;i<4;i++)
                {
                        int current_y = check_y+dir[i][0];
                        int current_x = check_x+dir[i][1];
                        if(current_y >= 0 && current_y < n && current_x >= 0 && current_x < m && maze[current_y][current_x] == '0')
                        {
                                if(dis_from_start[current_y][current_x] > dis_from_start[check_y][check_x]+1)
                                {
                                        start_list.push_back({current_y,current_x});
                                        dis_from_start[current_y][current_x] = dis_from_start[check_y][check_x]+1;
                                }
                        }
                        /*
                        for(int j=0;j<n;j++)
                        {
                                for(int k=0;k<m;k++)
                                {
                                        cout << dis_from_start[j][k] << " ";
                                }
                                cout << endl;
                        }
                        cout << endl;
                        */
                }

        }
        if(dis_from_start[end_y][end_x] == 12345)
        {
                return 0;
        }
        else
        {
                return dis_from_start[end_y][end_x];
        }
}

int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int n,m,start_x,start_y,end_x,end_y;
        cin >> n >> m >> start_y >> start_x >> end_y >> end_x;
        vector<string> maze(n);
        for(int i=0;i<n;i++)
        {
                cin >> maze[i];
        }
        cout << shortest(n,m,start_y-1,start_x-1,end_y-1,end_x-1,maze) << endl;
    }
    return 0;
}
