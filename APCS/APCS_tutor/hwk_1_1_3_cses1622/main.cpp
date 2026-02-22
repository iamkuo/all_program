#include <bits/stdc++.h>

using namespace std;

set<string> ans;
vector<bool> used;
string x,curr;

void brute_perm(int len)
{
    if(len == x.size())
    {
        ans.insert(curr);
        return;
    }
    for(int i=0;i<x.size();i++)
    {
        if(used[i]) continue;
        //if(i > 0 && x[i] == x[i-1] && !used[i-1]) continue;
        curr += x[i];
        used[i] = true;
        brute_perm(len+1);
        curr.pop_back();
        used[i] = false;
    }
}

int main()
{
    cin >> x;
    sort(x.begin(),x.end());
    used.resize(x.size(),false);
    curr = "";
    brute_perm(0);
    cout << ans.size() << "\n";
    for(string i : ans) cout << i << "\n";
    return 0;
}
