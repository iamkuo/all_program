#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int road[n];
    bool snow = false;
    for(int i=0;i<n;i++)
    {
        road[i] = 0;
    }
    int s[m];
    int e[m];
    for(int i=0;i<m;i++)
    {
        cin >> s[i] >> e[i];
        road[s[i]] = 1;
        road[e[i]-1] = -1;
    }
    int now = 0;
    for(int i=0;i<n;i++)
    {
        now += road[i];
        road[i] = now;
    }
    for(int i=0;i<n;i++)
    {
        if(!snow && road[i] == 0)
        {
            snow = true;
            cout << i << " ";
        }
        if(snow && road[i] == 1)
        {
            snow = false;
            cout << i << "\n";
        }
    }
    if(snow)
    {
        cout << n << "\n";
    }
    /*
    for(int i=0;i<n;i++)
    {
        cout << road[i] << " ";
    }
    */
}
