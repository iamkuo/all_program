#include<bits/stdc++.h>
using namespace std;
#define tiii tuple<int,int,int>
#define mt make_tuple
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> f;

bool is_valid(int &n,int x,int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int heuristic(int &x1,int &y1,int &x2,int &y2)
{
	return abs(x2-x1) + abs(y2-y1);
}

int a_star(auto &maze,int x1,int y1,int x2,int y2,int n)
{
	vector<vector<int>> g(n,vector<int>(n,8e7));
	vector<vector<int>> h(n,vector<int>(n));
	int nx,ny,f_val,cx,cy;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			h[i][j] = heuristic(i,j,x2,y2);
		}
	}
	f.resize(n,vector<int>(n,8e7));
	vector<vector<int>> px(n,vector<int>(n));
	vector<vector<int>> py(n,vector<int>(n));
	priority_queue<tiii,vector<tiii>,greater<>> pq; //(f,x,y)
	g[y1][x1] = 0;
	f[y1][x1] = g[y1][x1] + h[y1][x1];
	px[y1][x1] = x1;
	py[y1][x1] = y1;
	
	pq.push(mt(f[y1][x1],y1,x1));
	
	while(!pq.empty())
	{
		tie(f_val, cy, cx) = pq.top();
		//cout << "cy:" << cy << " cx:" << cx << endl;
		pq.pop();
		if(f_val > f[cy][cx]) continue;
		for(int i=0;i<4;i++)
		{
			nx = cx+dx[i];
			ny = cy+dy[i];
			if(is_valid(n,nx,ny) && maze[ny][nx] != '#' && g[cy][cx] + 1 < g[ny][nx])
			{
				g[ny][nx] = g[cy][cx] + 1;
				f[ny][nx] = g[ny][nx] + h[ny][nx];
				//cout << "updated y:" << ny << " x:" << nx << " to " << f[ny][nx] << endl;
				px[ny][nx] = cx;
				py[ny][nx] = cy;
				pq.push(mt(f[ny][nx],ny,nx));
			}
		}
	}
	int tmp_x = x2,tmp_y = y2;
	if(f[y2][x2] == 8e7) return -1;
	/*
	cout << "route: " << endl;
	while(px[tmp_y][tmp_x] != x1 || py[tmp_y][tmp_x] != y1)
	{
		tmp_x = px[tmp_y][tmp_x];
		tmp_y = py[tmp_y][tmp_x];
		maze[tmp_y][tmp_x] = '=';
	}
	for(auto i:maze)
	{
		for(auto j:i) cout << j;
		cout << endl;
	}
	*/
	return f[y2][x2];
}

int main()
{
	FAST_IO
	int n;
	string tmp;
	cin >> n;
	vector<vector<char>> maze(n,vector<char>(n));
	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		for(int j=0;j<n;j++)
		{
			maze[i][j] = tmp[j];
		}
	}
	int ans = a_star(maze,1,1,n-2,n-2,n);
	if(ans == -1) cout << "No solution!";
	else cout << ans+1;
	return 0;
}