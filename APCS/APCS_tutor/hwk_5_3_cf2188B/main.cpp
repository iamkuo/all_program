#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<bool> occupied(n,false);
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                occupied[i] = true;
                total++;
                if (i > 0) occupied[i - 1] = true;
                if (i < n - 1) occupied[i + 1] = true;
            }
        }
        for (int i = 1; i < n; i++) {
            if (!occupied[i-1]) {
                occupied[i] = true;
                total++;
                if (i > 0) occupied[i - 1] = true;
                if (i < n - 1) occupied[i + 1] = true;
            }
        }
        if(!occupied[0])
        {
            occupied[0] = true;
            total ++;
        }
        if((n > 1) && !occupied[n-1])
        {
            occupied[n-1] = true;
            total ++;
        }
        /*
        for(bool i:occupied)
        {
            if(i) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
        */
        cout << total << "\n";
    }

    return 0;
}
