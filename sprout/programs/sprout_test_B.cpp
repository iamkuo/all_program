#include<iostream>
using namespace std;
int m[1000000],n;
int max_left(int a)
{
	int max_left = 0;
	int idx = a;
	while(idx >= 2 && m[idx-1] == 1 && m[idx-2] == 0)
	{
		idx -= 2;
		max_left ++;
	}
	if(max_left > 0) return max_left;
	if(a > 0 && m[a-1] == 0) return 1;
	return 0;
}
int max_right(int a)
{
	int max_right = 0;
	int idx = a;
	while(idx <=n-1-2 && m[idx+1] == 1 && m[idx+2] == 0)
	{
		idx += 2;
		max_right ++;
	}
	if(max_right > 0) return max_right;
	if(a < n-1 && m[a+1] == 0) return 1;
	return 0;
}
int main()
{
	int left,right;
	cin >> n;
	for(int i=0;i<n;i++) cin >> m[i];
	for(int i=0;i<n;i++)
	{
		if(m[i] == 0) cout << -1;
		else
		{
			left = max_left(i);
			right = max_right(i);
			//cout << "left and right:" << left << " " << right << endl;
			if(left >= right) cout << left;
			else cout << right;
			
		}
		cout << " ";
	}
	
	
}