#include<bits/stdc++.h>
using namespace std;

int dfs(int idx,auto &dsu,auto &ans,auto &visited)
{
	visited[idx] = true;
	if(dsu[idx].empty()) return 1;
	for(int i : dsu[idx]){
		if(!visited[i]) ans[idx] += dfs(i,dsu,ans,visited);
		else ans[idx] += ans[i];
	}
	return ans[idx];
}

int main()
{
	int t,n,m,x,y,q;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> m;
		vector<vector<int>> dsu(n+1);//dsu[a] = b:a=>b
		for(int j=0;j<m;j++)
		{
			cin >> x >> y;
			dsu[x].push_back(y);
		}
		vector<int> ans(n+1,1);
		vector<bool> visited(n+1,false);
		for(int j=1;j<=n;j++) if(!visited[j]) dfs(j,dsu,ans,visited);
		cin >> q;
		for(int j=0;j<q;j++)
		{
			cin >> x;
			cout << ans[x] << endl;
		}
	}
	
}