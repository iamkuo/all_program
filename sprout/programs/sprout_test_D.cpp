#include<iostream>
using namespace std;
int main()
{
	int n,m,x;
	cin >> n >> m >> x;
	int one_side;
	for(int i=1;i*i<=x;i++) if(x % i == 0) one_side = i;
	cout << (one_side+x/one_side)*2;
}