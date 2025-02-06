#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    int days;
    bool done = false;
    vector<int> connects;
};

vector<node> nodes;

int gowork(int n)
{
    nodes[n].done = true;
    if(nodes[n].connects.size() == 0) return nodes[n].days;
    int maxday = gowork(nodes[n].connects[0]);
    for(int i=1;i<nodes[n].connects.size();i++)
    {
        if(!nodes[nodes[n].connects[i]].done)
        {
            int nowday = gowork(nodes[n].connects[i]);
            if(nowday > maxday)
            {
                maxday = nowday;
            }
        }
    }
    return (nodes[n].days + maxday);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int packs;
    vector<bool> mark;
    cin >> packs;
    for(int i=0;i<packs;i++)
    {
        int N;
        cin >> N;
        nodes.resize(N);
        mark.assign(N,false);
        for(int j=0;j<N;j++)
        {
            cin >> nodes[j].days;
            int point_number;
            cin >> point_number;
            for(int k=0;k<point_number;k++)
            {
                int connect;
                mark[connect] = true;
                cin >> connect;
                nodes[j].connects.push_back(connect-1);
            }
        }
        int nowday;
        int maxday = -1;
        for(int i=0;i<N;i++)
        {
            if(!mark[i])
            {
                nowday = gowork(i);
                if(nowday > maxday)
                {
                    maxday = nowday;
                }
            }
        }
        cout << maxday << endl;
        nodes.clear();
        mark.clear();
        /*
        for(int j=0;j<N;j++)
        {
            cout << nodes[j].days << " ";
        }
        cout << endl;
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<nodes[j].connects.size();k++)
            {
                cout << nodes[j].connects[k] << " ";
            }
            cout << endl;
        }
        */
    }
}
