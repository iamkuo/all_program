#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> x;

bool check(long long m)
{
    //cout << "checking " << m << "\n";
    long long sum = 0;//sum of the last subarray
    int curr = 0;//how many subarrays are full
    for(int i=0;i<n;i++)
    {
        if(x[i] > m) return false;
        if((sum+(long long)x[i]) > m)
        {
            //cout << "item " << x[i] << " nope\n";
            //x[i] cant fit
            //cout << "array " << curr << " full sum:" << sum << "\n";
            curr++;
            if(curr == k) return false;
            sum = 0;
        }
        else
        {
            //cout << "item " << x[i] << " ok\n";
        }
        sum += x[i];
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    x.resize(n);
    for(int i=0;i<n;i++) cin >> x[i];
    long long l=1,r=1e15,m;
    while(l<=r)
    {
        m = (l+r)/2;
        if(check(m))
        {
            r = m-1;
            //cout << m << " ok\n";
        }
        else
        {
            l = m+1;
            //cout << m << " nope\n";
        }
    }
    cout << l;
    return 0;
}
