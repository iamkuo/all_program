#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,d,x,money;
    money = 0;
    bool stock=true;
    int current = 1;
    cin >> n;
    cin >> d;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    x = a[0];
    //cout << "buy 1 " << a[0] << "\n";
    for(int i=1;i<n;i++)
    {
        if(stock)
        {
            if(a[i]>=x+d)
            {
                money += a[i]-x;
                x = a[i];
                stock = false;
            }
        }
        else
        {
            if(a[i]<=x-d)
            {
                x = a[i];
                stock = true;
            }
        }
    }
    cout << money;
}
