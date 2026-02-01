#include <bits/stdc++.h>
using namespace std;

vector<int> p;
int n,k;

bool possible(int x)
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    p.resize(n);
    for(int i=0;i<n;i++) cin >> p[i];
    int l=1,r=1e9,m;// [l,r]
    while(l<=r)
    {
        m = (l+r)/2;
        if(possible(m)) r = m-1;
        else r = m+1;
    }
    return 0;
}
