#include<iostream>
using namespace std;
int pow_digit(int x,int p)
{
	int ans = x;
	for(int i=0;i<p-1;i++)
	{
		ans *= x;
		ans %= 10;
	}
	//cout << ans << endl;
	return ans;
}
int main()
{
	int n,q,a[2000],l,r,k,sum;
	cin >> n >> q;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<q;i++)
	{
		sum = 0;
		cin >> l >> r >> k;
		for(int j=l-1;j<r;j++) sum += pow_digit(a[j],k);
		cout << sum % 10 << endl;
	}
}