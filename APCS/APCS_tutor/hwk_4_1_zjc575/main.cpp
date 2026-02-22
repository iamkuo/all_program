#include <bits/stdc++.h>
using namespace std;

set<int> p;
vector<int> p_sorted;
int n,k;

bool possible(int x)
{
    int last=0;//first point that dont have service
    int used_k = 0;
    for(int i=0;i<n;i++)
    {
        if(p_sorted[i] >= last)
        {
            used_k ++;
            if(used_k > k)
            {
                //cout << "x " << x << " nope" << "\n";
                return false;
            }
            last = p_sorted[i]+x+1;
            //cout << "flag at " << p_sorted[i]+x/2.0 << "\n";
        }
    }
    //cout << "x " << x << " ok" << "\n";
    return true;
}

int main()
{
    int tmp;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        p.insert(tmp);
    }
    for(int i : p) p_sorted.push_back(i);
    int l=1,r=1e9,m;//[l,r]
    while(l<=r)
    {
        m = (l+r)/2;
        if(possible(m)) r = m-1;
        else l = m+1;
    }
    cout << l;
    return 0;
}
