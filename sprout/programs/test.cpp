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
		else worker ++;
		if(worker > m) return false;
	}
	return true;
	
}
int main()
{
    int n,m,c;
    cin >> n >> m;
    vector<int> text(n);
    for(int i=0;i<n;i++) cin >> text[i];
    while(1)
    {
        cin >> c;
        cout << check(text,n,m,c) << endl;
    }
}