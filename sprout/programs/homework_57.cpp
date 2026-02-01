#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,x;
	priority_queue<int, vector<int>, greater<int>> heap;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> x;
		if(x == 1)
		{
			 cin >> x;
			 heap.push(x);
		}
		else if(!heap.empty())
		{
			cout << heap.top() << endl;
			heap.pop();
		}
		else
		{
			cout << "empty!" << endl;
		}
	}
}