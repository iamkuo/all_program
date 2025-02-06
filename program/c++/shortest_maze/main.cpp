#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    char type;
    int x,y;
    int distance_now = 123456789;
    bool searched = false;
};

int main()
{
    int n;
    cin >> n;
    node maze[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            maze[i][j].type = getchar();
            if(maze[i][j].type == '\n')
            {
                maze[i][j].type = getchar();
            }
            maze[i][j].x = j;
            maze[i][j].y = i;
            if(i == 1 && j == 1)
            {
                maze[i][j].distance_now = 1;
            }
        }
    }
    int min_dis_x;
    int min_dis_y;
    int min_dis = 123456789;
    while(true)
    {
        min_dis = 123456789;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maze[i][j].distance_now < min_dis && maze[i][j].type == '.' && maze[i][j].searched == false)
                {
                    min_dis = maze[i][j].distance_now;
                    min_dis_x = maze[i][j].x;
                    min_dis_y = maze[i][j].y;
                }
            }
        }
        if(min_dis == 123456789)
        {
            cout << "No solution!";
            break;
        }
        if(maze[min_dis_y][min_dis_x-1].type == '.' && maze[min_dis_y][min_dis_x].distance_now + 1 < maze[min_dis_y][min_dis_x-1].distance_now && maze[min_dis_y][min_dis_x-1].searched == false)
        {
            maze[min_dis_y][min_dis_x-1].distance_now = maze[min_dis_y][min_dis_x].distance_now + 1;
        }
        if(maze[min_dis_y][min_dis_x+1].type == '.' && maze[min_dis_y][min_dis_x].distance_now + 1 < maze[min_dis_y][min_dis_x+1].distance_now && maze[min_dis_y][min_dis_x+1].searched == false)
        {
            maze[min_dis_y][min_dis_x+1].distance_now = maze[min_dis_y][min_dis_x].distance_now + 1;
        }
        if(maze[min_dis_y-1][min_dis_x].type == '.' && maze[min_dis_y][min_dis_x].distance_now + 1 < maze[min_dis_y-1][min_dis_x].distance_now && maze[min_dis_y-1][min_dis_x].searched == false)
        {
            maze[min_dis_y-1][min_dis_x].distance_now = maze[min_dis_y][min_dis_x].distance_now + 1;
        }
        if(maze[min_dis_y+1][min_dis_x].type == '.' && maze[min_dis_y][min_dis_x].distance_now + 1 < maze[min_dis_y+1][min_dis_x].distance_now && maze[min_dis_y+1][min_dis_x].searched == false)
        {
            maze[min_dis_y+1][min_dis_x].distance_now = maze[min_dis_y][min_dis_x].distance_now + 1;
        }
        maze[min_dis_y][min_dis_x].searched = true;
        if(min_dis_y == n-1 && min_dis_x == n-1)
        {
            cout << maze[n-1][n-1].distance_now;
        }
    }
    return 0;
}
