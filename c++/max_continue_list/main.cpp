#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> dat;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int n,q,l,r;
    int now;
    int max_possible = 0;
    int ans;
    int start_ans;
    int stop_ans;
    int start = 0;
    int stop = 0;
    int case_x = 1;
    //while(cin >> n >> q)
    //{
    cin >> n >> q;
        cout << "Case " << case_x << ":" << "\n";
        case_x ++;
        dat.resize(n);
        for(int i=0;i<n;i++)
        {
            cin >> dat[i];
        }
        for(int i=0;i<q;i++)
        {
            cin >> l >> r;
            max_possible = dat[l];
            start = 0;
            stop = 0;
            start_ans = 0;
            stop_ans = 0;
            ans = max_possible;
            for(int j=1;j<r-l+1;j++)
            {
                if(max_possible+dat[l-1+j] >= dat[l-1+j])
                {
                    stop = j;
                    max_possible += dat[l-1+j];
                }
                else
                {
                    start = j;
                    max_possible = dat[l-1+j];
                }
                if(max_possible > ans)
                {
                    ans = max_possible;
                    start_ans = start;
                    stop_ans = j;
                }
            }
            cout << start_ans+l << " " << stop_ans+l << " " << ans << "\n";
        }
    //}
}
