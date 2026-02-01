#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> &text,int n,int m,int c)
{
	int worker = 1;
	int payload = 0;
	for(int i=0;i<n;i++)
	{
		if(text[i] > c) return false;
		
		if(c-payload >= text[i]) payload += text[i];
		else
		{
		    worker ++;
		    payload = text[i];
		}
		if(worker > m) return false;
	}
	return true;
}
int main()
{
	int t,n,m,l,r,mid;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> m;
		vector<int> text(n);
		for(int i=0;i<n;i++) cin >> text[i];
		l = 1;
		r = 1e9;
		while(l<r)
		{
			mid = (l+r)/2;
			if(check(text,n,m,mid)) r = mid;
			else l = mid+1;
		}
		cout << l << endl;
	}
}