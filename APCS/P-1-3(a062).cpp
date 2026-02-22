#include<bits/stdc++.h>
using namespace std;

vector<int> p;

long long int cut(int l,int r)
{
    if(r-l == 1) return 0;
    int m_pos = (p[l]+p[r])/2;
    int m_cut = lower_bound(p.begin()+l,p.begin()+r,m_pos)-p.begin();
    if(m_cut == r) m_cut--;
    else if(p[m_cut]-m_pos > m_pos-p[m_cut-1]) m_cut --;
    return p[r]-p[l] + cut(l,m_cut) + cut(m_cut,r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,L;
    cin >> n >> L;
    p.resize(n+2);
    p[0] = 0;
    p[n+1] = L;
    for(int i=1;i<=n;++i) cin >> p[i];
    cout << cut(0,n+1);
    return 0;
}
