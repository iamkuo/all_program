#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main()
{
    int n,dir;
    cin >> n >> dir;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> grid[i][j];
    }
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int x = n/2;
    int y = n/2;
    //cout << "print " << y << " " << x << "\n";
    cout << grid[y][x];
    visited[y][x] = true;
    x += dx[dir];
    y += dy[dir];
    int cnt = 1,goal = n*n;
    while(cnt != goal)
    {
        //cout << "\nprint " << y << " " << x << "\n";
        cout << grid[y][x];
        visited[y][x] = true;
        if(!visited[y+dy[(dir+1)%4]][x+dx[(dir+1)%4]]) dir = (dir+1)%4;
        x += dx[dir];
        y += dy[dir];
        cnt++;
    }
    return 0;
}
