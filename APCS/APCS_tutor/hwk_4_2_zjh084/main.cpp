#include <bits/stdc++.h>
using namespace std;

vector<int> h,w;
int n,k;

bool check(int x)
{
    //cout << "checking " << x << "\n";
    int len=0,curr=0;
    for(int i=0;i<n;i++)
    {
        //cout << "scanning " << i;
        if(h[i] >= x)
        {
            //cout << " ok" << "\n";
            len++;
            if(len == w[curr])
            {
                //cout << "put down piece " << curr << "\n";
                curr++;
                len = 0;
                if(curr == (k)) return true;
            }
        }
        else
        {
            //cout << " nope" << "\n";
            len = 0;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    h.resize(n);
    w.resize(k);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<k;i++) cin >> w[i];
    int l=1,r=1e9,m;
    while(l<=r)
    {
        m = (l+r)/2;
        if(check(m))
        {
            //cout << m << " ok" << "\n";
            l = m + 1;
        }
        else
        {
            //cout << m << " nope" << "\n";
            r = m-1;
        }
    }
    cout << r;
    return 0;
}
