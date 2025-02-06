#include <bits/stdc++.h>

using namespace std;

class learn
{
    public:
    int d,s,t;
};
bool learn_sort(learn a,learn b)
{
    if(a.d<b.d)
    {
        return true;
    }
    else if(a.d == b.d && a.s<b.s)
    {
        return true;
    }
    else if(a.s == b.s && a.t<b.t)
    {
        return true;
    }
    return false;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    learn dat[n];
    for (int i=0;i<n;i++)
    {
        cin >> dat[i].d;
        cin >> dat[i].s;
        cin >> dat[i].t;
    }
    sort(dat,dat+n,learn_sort);
    cout << "\n";
    for (int i=0;i<n;i++)
    {
        cout << dat[i].d << " ";
        cout << dat[i].s << " ";
        cout << dat[i].t << "\n";
    }
}
