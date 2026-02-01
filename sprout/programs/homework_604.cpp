#include<bits/stdc++.h>
using namespace std;

void bfs(int x,auto &adj_list,auto &sex,bool &ans)
{
	queue<int> q;
	/*
	cout << "dfs " << x << endl;
	cout << "child: ";
	for(int i:adj_list[x]) cout << i << " ";
	cout << endl;
	*/
	sex[x] = 1;
	q.push(x);
	while(!q.empty())
	{
		for(int i:adj_list[q.front()])
		{
			if(sex[i] == sex[q.front()])
			{
				ans = false;
				break;
			}
			if(sex[i] == -1)
			{
				sex[i] = 3 - sex[q.front()];
				q.push(i);
			}
		}
		if(!ans) break;
		q.pop();
	}
	
}


int main()
{
	int t,n,m,a,b;
	bool ans;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		ans = true;
		cin >> n >> m;
		vector<vector<int>> adj_list(n);
		vector<int> sex(n,-1);//-1:nope 1:man 2:woman
		for(int j=0;j<m;j++)
		{
			cin >> a >> b;
			adj_list[a].push_back(b);
			adj_list[b].push_back(a);
		}
		for(int j=0;j<n;j++)
		{
			if(sex[j] == -1) bfs(j,adj_list,sex,ans);
			if(!ans) break;
		}
		if(ans) cout << "NORMAL." << endl;
		else cout << "RAINBOW." << endl;
	}
}