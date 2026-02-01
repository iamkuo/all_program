#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(auto &a,auto &b,auto &c,int n,int m,int k)
{
	static vector<int> a_now(n);
	for(int i=0;i<n;i++) a_now[i] = a[i] + b[i]*m;
	sort(a_now.begin(),a_now.end());
	int a_idx=0,b_idx=0;
	while(b_idx<n)
	{
		if(b[a_idx] > a[a_idx])
		{
			a_idx ++;
			b_idx ++;
		}
		else
		{
			b_idx ++;
		}
		if(a_idx == k) return true;
	}
	return false;
	
}

int main()
{
	int t,n,k;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> k;
		vector<int> a(n),b(n),c(n);
		for(int j=0;j<n;j++) cin >> a[j] >> b[j];
		for(int j=0;j<n;j++) cin >> c[j];
		sort(c.begin(),c.end());

		int l=0,m,r=1e9;
		while(l<=r)
		{
			m = (l+r)/2;
			if(check(a,b,c,n,m,k))r = m-1;
			else l = m+1;
		}
		if(l == 1e9+1) cout << -1 << endl;
		else cout << l << endl;
	}
}