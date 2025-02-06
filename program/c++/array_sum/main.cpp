#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int s,t,n,m,r;
int dis,diff_sum;
vector<int> a,b;

void array_compare(int x,int y)
{
    int a_now,b_now;
    int a_sum = 0;
    int b_sum = 0;
    dis = 0;
    diff_sum = 0;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<t;j++)
        {
            a_now = a[i*t+j];
            b_now = b[(i+x)*m+(j+y)];
            a_sum += a_now;
            b_sum += b_now;
            //cout << a_now << " " << b_now << "\n";
            if(a_now != b_now)
            {
                dis ++;
            }
        }
    }
    diff_sum = abs(a_sum-b_sum);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t >> n >> m >> r;
    a.resize(s*t);
    b.resize(n*m);
    int ok_sum = 0;
    int diff_sum_min = 901;
    for(int i=0;i<s*t;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n*m;i++)
    {
        cin >> b[i];
    }
    for(int i=0;i<=n-s;i++)
    {
        for(int j=0;j<=m-t;j++)
        {
            array_compare(i,j);
            if(dis <= r)
            {
                ok_sum ++;
                if(diff_sum < diff_sum_min)
                {
                    diff_sum_min = diff_sum;
                }
            }
        }
    }
    cout << ok_sum << "\n";
    if(diff_sum_min == 901)
    {
        cout << -1;
    }
    else
    {
        cout << diff_sum_min;
    }
}
