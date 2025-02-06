#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class human
{
public:
    long long int s,t;
    int life,idx;
};
bool human_sort(human a,human b)
{
    return a.idx<b.idx;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int competitor_1,competitor_2;
    cin >> n;
    cin >> m;
    vector<human> all(n);
    vector<int> win,lose;
    for(int i=0;i<n;i++)
    {
        dat[i].life = m;
    }
    for(int i=0;i<n;i++)
    {
         cin >> dat[i].s;
    }
    for(int i=0;i<n;i++)
    {
         cin >> dat[i].t;
    }
    for (int i=0;i<n;i++)
    {
        cin >> dat[i].idx;
        dat[i].idx-=1
    }
    sort(all.begin(),all.end(),human_sort());
    while(all.size()>1)
    {
        long long int a,b,c,d;
        a = all[i].s
        b = all[i].t
        c = all[i+1].s
        d = all[i+1].t
        for (int i=0;i<all.size()/2;i+2)
        {

            if(all[i].s*all[i].t>all[i+1].s*all[i+1].t)
            {
                all[i+1].life --;
                all[i].s += c*d/(2*b);
                all[i].t += c*d/(2*a);
                all[i+1].s += c/2;
                all[i+1].t += d/2;
                win.push_back(all[i]);
                lose.push_back(all[i+1]);

            }
            else
            {
                all[i].life --;
                all[i+1].s += a*b/(2*d);
                all[i+1].t += a*b/(2*c);
                all[i].s += a/2;
                all[i].t += b/2;
                win.push_back(all[i]);
                lose.push_back(all[i+1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if
        }
        if(all.size()%2==1)
        {
            win.push_back(all[all.size()-1]);
        }


    }




}
