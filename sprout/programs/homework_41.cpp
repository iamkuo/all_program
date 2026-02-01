#include<bits/stdc++.h>
using namespace std;

int x[4] = {1,0,-1,0};
int y[4] = {0,1,0,-1};

void dfs(int j, int k, int &h, int &w, auto &pool, auto &visited)
{
	visited[j][k] = true;
	for(int i=0;i<4;i++)
	{
		if(j+y[i]<0 || j+y[i]>=h || k+x[i]<0 || k+x[i]>=w) continue;
		if(pool[j+y[i]][k+x[i]] == 1 || visited[j+y[i]][k+x[i]]) continue;
		dfs(j+y[i],k+x[i],h,w,pool,visited);
	}
	return;
}

int main()
{
	int t,h,w,ans;
	string tmp;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		ans = 0;
		cin >> h >> w;
		vector<vector<int>> pool(h, vector<int>(w));
		vector<vector<bool>> visited(h,vector<bool>(w,false));
		for(int j=0;j<h;j++)
		{
			cin >> tmp;
			for(int k=0;k<w;k++)
			{
				if(tmp[k] == '#') pool[j][k] = 1;
				else pool[j][k] = 0;
			}
		}
		for(int j=0;j<h;j++)
		{
			for(int k=0;k<w;k++)
			{
				if(pool[j][k] == 0 && !visited[j][k])
				{
					ans ++;
					//cout << "yee" << endl;
					dfs(j,k,h,w,pool,visited);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}