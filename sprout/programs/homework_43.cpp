#include<bits/stdc++.h>

using namespace std;
int main()
{
	int t,n,m,ans,nx,ny;
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	string tmp;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> m;
		queue<pair<int,int>> next;
		vector<vector<char>> maze(n,vector<char>(m));
		vector<vector<short int>> path(n,vector<short int>(m,-1));
		vector<vector<bool>> visited(n,vector<bool>(m,false));
		ans = -1;
		for(int j=0;j<n;j++)
		{
			cin >> tmp;
			for(int k=0;k<m;k++)
			{
				maze[j][k] = tmp[k];
				if(tmp[k] == 'K')
				{
					path[j][k] = 0;
					next.push(make_pair(j,k));
				}
			}
		}
		while(!next.empty())
		{
			int &y = next.front().first;
			int &x = next.front().second;
			//cout << x << " " << y << endl;
			visited[y][x] = true;
			if(maze[y][x] == '@')
			{
				ans = path[y][x];
				break;
			}
			for(int j=0;j<4;j++)
			{
				nx = x + dx[j];
				ny = y + dy[j];
				if(ny >= 0 && ny < n && nx >= 0 && nx < m && maze[ny][nx] != '#' && !visited[ny][nx])
				{
					visited[ny][nx] = true;
					next.push(make_pair(ny,nx));
					path[ny][nx] = path[y][x] + 1;
				}
			}
			next.pop();
		}
		//cout << visited[1][3] << endl;
		if(ans == -1) cout << "= =\"" << endl;
		else cout << ans << endl;
	}
}