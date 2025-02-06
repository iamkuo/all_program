#include<bits/stdc++.h>
using namespace std;
bool string_compare(string a,string b)
{
    return (a<b);
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    int ans=0;
    vector <string> dat(m);
    for (int i=0;i<m;i++)
    {
        cin >> dat[i];
    }
    sort(dat.begin(),dat.end(),string_compare);
    for (int i=0;i<m;i++)
    {
        int string_size = dat[i].size();
        for(int j=1;(j*2+1)<=string_size;j++)
        {
            if(dat[i].compare(0,j,dat[i],string_size-j,j) == 0)
            {
                string target = dat[i].substr(j,string_size-j*2);
                int l=0;
                int r=m-1;
                while(l<=r)
                {
                    int center = (l+r)/2;
                    if(target > dat[center]) l=center+1;
                    else if(target < dat[center]) r=center-1;
                    else
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}
