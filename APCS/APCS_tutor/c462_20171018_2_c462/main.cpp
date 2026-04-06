#include <bits/stdc++.h>
using namespace std;

bool if_upper(char c) {return (c-'a'<0);}

int main()
{
    int k;
    cin >> k;
    string s; //-'a'<0:upper else:lower
    cin >> s;
    bool curr_t = if_upper(s[0]);
    int curr_l = 1,s_l = 1,ans=1;
    cout << curr_t << " " << curr_l << " " << s_l;
    for(int i=1;i<s.size();i++)
    {
        if(if_upper(s[i]) == curr_t)
        {
            if(curr_t < k)
            {
                curr_l ++;
                s_l++;
            }
            else // not legal
            {
                curr_t = !curr_t;
                curr_l = 1;
                s_l = 1;
            }
        }
        else
        {
            if(curr_l == k) // switch type if reach k
            {
                curr_t = !curr_t;
                curr_l = 1;
                s_l++;
            }
            else // not legal
            {
                curr_t = !curr_t;
                curr_l = 1;
                s_l = 1;
            }
        }
        if(s_l > ans) ans = s_l;
    }
    cout << ans;
    return 0;
}
