#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

string f_t,m_t;
int f_now;
vector<int> f_idx(26); //stores position of node in f_t by alphabetical order
vector<int> m_idx(26); //stores position of node in m_t by alphabetical order

int toint(char x) {return x - 'A';}

int build(int l,int r,vector<pii> &el)
{
    if(l>r) return -1;
    int root = toint(f_t[f_now]);
    f_now++;
    el[root].f = build(l,m_idx[root]-1,el);
    el[root].s = build(m_idx[root]+1,r,el);
    return root;
}

void output(int x,vector<pii> &el)
{
    if(x == -1) return;
    output(el[x].f,el);
    output(el[x].s,el);
    cout << (char)('A'+x);
}

int main()
{
    while(cin >> f_t >> m_t)
    {
        f_now = 0;
        vector<pii> el(26,{-1,-1});
        for(int i=0;i<f_t.size();i++)
        {
            f_idx[toint(f_t[i])] = i;
            m_idx[toint(m_t[i])] = i;
        }
        build(0,f_t.size()-1,el);
        output(toint(f_t[0]),el);
        cout << "\n";
    }
    return 0;
}
