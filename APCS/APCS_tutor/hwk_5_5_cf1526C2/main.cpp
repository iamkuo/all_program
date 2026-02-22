#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a;
    cin >> n;
    ll sum = 0,ans=0;
    priority_queue<int,vector<int>,greater<int>> bad_pot;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if(sum + a >= 0)
        {
            sum += a;
            ans ++;
            if(a < 0) bad_pot.push(a);
        }
        else if(!bad_pot.empty() && bad_pot.top() < a)
        {
            sum += a-bad_pot.top();
            bad_pot.pop();
            bad_pot.push(a);
        }
    }
    cout << ans << "\n";
    return 0;
}
