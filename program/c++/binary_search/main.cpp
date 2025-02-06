#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> dat;
bool bin_loc(int x)
{
    int left = 0;
    int right = dat.size()-1;
    int middle;
    while(left <= right)
    {
        middle = (left+right)/2;
        if(dat[middle]>x) right = middle-1;
        else if(dat[middle]<x) left = middle+1;
        if(dat[middle] == x)return true;
    }
    return false;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int N,Q;
    cin >>  N >> Q;
    dat.resize(N);
    int checking;
    for(int i=0;i<N;i++) cin >> dat[i];
    for(int i=0;i<Q;i++)
    {
        cin >> checking;
        if(bin_loc(checking)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
