#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    string beg = s.substr(0,s.find(t));
    string last = s.substr(s.find(t)+t.size(),s.size()-beg.size()-t.size());
    string t_swap = "";
    for(int i=t.size()-1;i>=0;i--)
    {
        t_swap += t[i];
    }
    s = beg+t_swap+last;
    for(int i=s.size()-1;i>=0;i--)
    {
        cout << s[i];
    }
}
