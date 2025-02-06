#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int bin_search(int x)
{
    int left = 0;
    int right = p.size();
    int middle;
    while(right-left>0)
    {
        middle = (left+right)/2;
        if(p[middle]>=x && p[middle-1]<x)
        {
            return middle;
        }
        else if(p[middle] > x)
        {
            right = middle-1;
        }
        else if(p[middle] < x)
        {
            left = middle +1;
        }
    }
}

int main()
{
    int n,m;
    int t=0;
    cin >> n >> m;
    p.resize(n);
    int q[m];
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        if(i != 0)
        {
            p[i] += p[i-1];
        }
    }
    for(int i=0;i<m;i++)
    {
        cin >> q[i];
        if(i != 0)
        {
            q[i] += q[i-1];
        }
        q[i] %= p[n-1];
        t += bin_search(q[i])+1;
        t %= p[n-1];
    }
    cout << t;


    return 0;
}
