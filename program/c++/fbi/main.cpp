#include <bits/stdc++.h>

using namespace std;

class a_pair
{
public:
    int x,y;
};
class agent
{
public:
    vector<int> link;
    int group;
};

bool organization(int j,agent *agents_new)
{
    int new_group;
    if(agents_new[j].group < 0)
    {
        agents_new[j].group = 1;
    }
    new_group = (agents_new[j].group+1)%2;
    for(int i=0;i<agents_new[j].link.size();i++)
    {
        if(agents_new[agents_new[j].link[i]].group<0)
        {
            agents_new[agents_new[j].link[i]].group = new_group;
            if(organization(agents_new[j].link[i],agents_new))
            {
                return true;
            }
        }
        else if(agents_new[agents_new[j].link[i]].group != new_group)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    a_pair pairs_known[m];
    agent agents_known[n];
    agent agents_new[n];
    for(int i=0;i<n;i++)
    {
        agents_known[i].group = -1;
    }
    int p,k;
    cin >> p >> k;
    a_pair pairs_new[k];

    for(int i=0;i<p;i++)
    {
        copy(agents_known,agents_known+n,agents_new);
        for(int j=0;j<k;j++)
        {
            cin >> pairs_new[j].x;
            cin >> pairs_new[j].y;
            agents_new[pairs_new[j].x].link.push_back(pairs_new[j].y);
            agents_new[pairs_new[j].y].link.push_back(pairs_new[j].x);
        }
        for(int j=0;j<n;j++)
        {
            if(agents_new[j].link.size() > 0)
            {
                if(organization(j,agents_new))
                {
                    cout << i+1 <<"\n";
                    break;
                }
            }
        }
    }





    return 0;
}
