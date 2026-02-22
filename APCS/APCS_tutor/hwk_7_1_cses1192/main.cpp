#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> maze; // '#'=false, '.'=true
vector<vector<bool>> visited;
int n,m;

bool check(int y,int x) {return y >= 0 && y<n && x >= 0 && x<m && maze[y][x] && !visited[y][x];}

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
void dfs(int y,int x)
{
    visited[y][x] = true;
    for(int i=0;i<4;i++)
    {
        if(check(y+dy[i],x+dx[i])) dfs(y+dy[i],x+dx[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    maze.resize(n,vector<bool>(m));
    visited.resize(n,vector<bool>(m,false));
    string tmp;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        for(int j=0;j<m;j++) maze[i][j] = (tmp[j] == '#' ? false : true);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maze[i][j] && !visited[i][j])
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
