#include <bits/stdc++.h>
using namespace std;
#define stats vector<uint8_t>
#define state pair<int,stats> //(shortest path to state currently,states)
#define f first
#define s second
#define mp make_pair

set<stats> visited;
queue<state> bfs;
stats tmp;
int n,t,check;

int gcd(int x, int y) {
    while((x %= y) && (y %= x));
    return x+y;
}

void add_stats(int step) // attempt to add stats
{
    //for(int i:tmp) cout << i << " ";
    for(int i=0;i<n;i++)
    {
        if(tmp[i] == t)
        {
            //cout << "ok\n";
            cout << step+1;
            exit(0);
        }
    }
    if(!visited.count(tmp))
    {
        bfs.push(mp(step+1,tmp));
        visited.insert(tmp);
        //cout << "push step " << step+1 << "\n";
    }
    else
    {
        //cout << "nope\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> m(n);
    for(int i=0;i<n;i++) cin >> m[i];
    cin >> t;
    bool possible = false;
    for(int i=0;i<n;i++)
    {
        if(m[i] == t)
        {
            cout << 1;
            return 0;
        }
        else if(m[i] > t)
        {
            possible = true;
        }
    }
    if(!possible)
    {
        cout << -1;
        return 0;
    }
    check=m[0];
    possible = true;
    for(int i=1;i<n;i++)
    {
        check = gcd(check,m[i]);
        if(check == 0)
        {
            possible = false;
            break;
        }
    }
    if(!possible || t%check != 0)
    {
        cout << -1;
        return 0;
    }
    visited.insert(stats(n,0));
    bfs.push(mp(0,stats(n,0)));
    while(!bfs.empty())
    {
        int &step = bfs.front().f;
        stats &now = bfs.front().s;
        tmp = bfs.front().s;
        for(int i=0;i<n;i++)
        {
            tmp[i] = m[i];
            add_stats(step);
            tmp[i] = now[i];
        }
        for(int i=0;i<n;i++)
        {
            tmp[i] = 0;
            add_stats(step);
            tmp[i] = now[i];
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //i->j
                check = min(m[j]-now[j], (int)now[i]);
                tmp[i] -= check;
                tmp[j] += check;
                add_stats(step);
                tmp[i] = now[i];
                tmp[j] = now[j];
                //j->i
                check = min(m[i]-now[i], (int)now[j]);
                tmp[j] -= check;
                tmp[i] += check;
                add_stats(step);
                tmp[i] = now[i];
                tmp[j] = now[j];
            }
        }
        bfs.pop();
    }
    cout << -1; // theoreticly not going to run
    return 0;
}
