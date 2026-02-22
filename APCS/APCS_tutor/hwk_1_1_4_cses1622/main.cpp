#include <bits/stdc++.h>

using namespace std;

string n;
vector<string> ans;

int main()
{
    cin >> n;
    sort(n.begin(),n.end());
    do
    {
        ans.push_back(n);
    }
    while(next_permutation(n.begin(),n.end()));
    cout << ans.size() << "\n";
    for(string i : ans) cout << i << "\n";
    return 0;
}
