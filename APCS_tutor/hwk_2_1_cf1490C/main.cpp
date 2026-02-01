#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    bool found;
    long long int cubes[10000],x;
    for(int i=1;i<10000;i++) cubes[i] = (long long)i*i*i;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> x;
        found = false;
        for(int i=1;cubes[i]<x;i++)
        {
            if(binary_search(cubes+1,cubes+10000,x-cubes[i]))
            {
                found = true;
                cout << "yes" << "\n";
                break;
            }
        }
        if(!found) cout << "no" << "\n";
    }
    return 0;
}
