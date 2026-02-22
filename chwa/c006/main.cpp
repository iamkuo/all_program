#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string,uint16_t> songs; //(name,count)
    uint16_t n;
    cin >> n;
    string s;
    for(uint16_t i=0;i<n;i++)
    {
        cin >> s;
        songs[s] ++;
    }
    uint16_t ans = 0;
    string name;
    for(pair<string,uint16_t> i : songs)
    {
        if(i.second > ans)
        {
            name = i.first;
            ans = i.second;
        }
    }
    cout << name << " " << ans;
    return 0;
}
