#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    cin >> n >> d;
    int dat[3];
    int sum = 0;
    int price = 0;
    for(int i=0;i<n;i++)
    {
        cin >> dat[0] >> dat[1] >> dat[2];
        sort(dat,dat+3);
        if(dat[2]-dat[0]>=d)
        {
            sum ++;
            price += (dat[0]+dat[1]+dat[2])/3;
        }
    }
    cout << sum << " " << price;
}
