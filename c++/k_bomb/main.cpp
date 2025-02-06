#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    int now = 0;
    cin >> n >> m >> k;
    vector<int> peoples(n);
    for(int i=0;i<n;i++) peoples[i] = i+1;
    for (int i=0;i<k;i++) {
        now = (now+m-1)%peoples.size();
        peoples.erase(peoples.begin()+now);
        if(now == peoples.size()) now = 0;
    }
    cout << peoples[now];
}
