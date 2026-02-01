#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,tmp,max_x = -1;
    cin >> n;
    vector<int> x(1e6+1);
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        x[tmp] ++;
        if(tmp > max_x) max_x = tmp;
    }
    vector<int> check(max_x+1,0);// how many x can it divide
    for(int i=1;i<=max_x;i++)
    {
        for(int j=i;j<=max_x;j+=i)
        {
            if(x[j] > 0) check[i] += x[j];
        }
    }
    for(int i=max_x;i>=0;i--)
    {
        if(check[i]>=2)
        {
            cout << i;
            return 0;
        }
    }
}
