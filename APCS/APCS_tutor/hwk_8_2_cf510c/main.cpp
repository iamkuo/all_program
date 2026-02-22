#include <bits/stdc++.h>
using namespace std;

bool el[26][26]; // DAG i -> j
int in_deg[26];

int toi(char x) {return x-'a';}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int j;
    string now,pre;
    cin >> now;
    for(int i=0;i<n-1;i++)
    {
        pre = now;
        cin >> now;
        j=0;
        while(j < pre.size() && j < now.size())
        {
            if(el[toi(now[j])][toi(pre[j])])
            {
                cout << "Impossible";
                return 0;
            }
            if(pre[j] != now[j] && !el[toi(pre[j])][toi(now[j])])
            {
                in_deg[toi(now[j])] ++;
                el[toi(pre[j])][toi(now[j])] = true;
                break;
            }
            j++;
        }
        if(j == now.size() && pre.size() > now.size())
        {
            cout << "Impossible";
            return 0;
        }
    }
    queue<int> bfs;
    for(int i=0;i<26;i++)
    {
        if(in_deg[i] == 0) bfs.push(i);
    }
    int ans[26];
    int checked = 0;
    while(!bfs.empty())
    {
        int curr = bfs.front();
        bfs.pop();
        ans[checked] = curr;
        checked++;
        for(int i=0;i<26;i++)
        {
            if(el[curr][i])
            {
                in_deg[i]--;
                if(in_deg[i] == 0) bfs.push(i);
            }
        }
    }
    if(checked != 26)
    {
        cout << "Impossible";
        return 0;
    }
    for(int i : ans) cout << (char)('a'+i);
    return 0;
}
