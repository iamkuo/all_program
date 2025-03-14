#include<iostream>
using namespace std;

int x[1000000],a,b,n;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) cin >> x[i];
	cin >> a >> b;
	if(a == 0) cout << b;
	if(b == 0) cout << a*n;
}