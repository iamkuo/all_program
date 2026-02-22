#include <bits/stdc++.h>
using namespace std;

int n, max_d = 0;
vector<vector<int>> el;

int dfs(int x)
{
    int f = 0, s = 0;
    for (int child : el[x])
    {
        int d = dfs(child) + 1;
        if (d > f)
        {
            s = f;
            f = d;
        }
        else if (d > s) s = d;
    }
    max_d = max(max_d, f+s);
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    el.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        while (cin >> x && x != -1) el[i].push_back(x);
    }
    dfs(0);
    cout << max_d << "\n";
}
