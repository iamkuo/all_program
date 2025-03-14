#include<iostream>
using namespace std;

int main()
{
	int n,a[1000];
	cin >> n;
	int min_idx,min_num = 1001;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i] < min_num)
		{
			min_idx = i;
			min_num = a[i];
		}
	}
	if(min_idx == 0) cout << 0;
	else cout << "1\n1 " << min_idx+1;
	return 0;
}