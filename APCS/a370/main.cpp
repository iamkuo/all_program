#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,k,ans = 0,t_pos,max_abc;
    cin >> m >> n >> k;
    vector<string> whls(m);
    vector<int> pos(m,0);
    for(int i=0;i<m;i++) cin >> whls[i];
    for(int i=0;i<k;i++)
    {
        vector<int> abc(26,0);
        for(int j=0;j<m;j++)
        {
            cin >> t_pos;
            t_pos = (pos[j] - t_pos) % n;
            if(t_pos < 0) t_pos = n-t_pos;
            abc[whls[j][t_pos] - 'a'] ++;
        }
        for(int j=0;j<n;j++)
        {

        }
        max_abc = -1;
        for(int j=0;j<26;j++)
        {
            if(abc[j] > max_abc) max_abc = abc[j];
        }
        ans += max_abc;
        cout << "round" << i << " max " << max_abc << "\n";
    }
    cout << ans;
    return 0;
}
