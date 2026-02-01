#include <bits/stdc++.h>

using namespace std;

string n,curr;
int perm_count;
bool done;
int j,k;
vector<string> ans;

bool next_perm()
{
    //cout << n << "\n";
    done = true;
    for(int i=0;i<n.size()-1;i++)
    {
        if(n[i] < n[i+1])
        {
            done = false;
            break;
        }
    }
    if(done) return false;
    for(int i=n.size()-1;i>0;i--)
    {
        if(n[i-1] < n [i])
        {
            j = i-1;
            break;
        }
    }
    for(int i=n.size()-1;i>=0;i--)
    {
        if(n[i] > n[j])
        {
            k = i;
            break;
        }
    }
    swap(n[j],n[k]);
    reverse(n.begin()+j+1,n.end());
    ans.push_back(n);
    return true;
}

int main()
{
    cin >> n;
    sort(n.begin(),n.end());
    ans.push_back(n);
    curr = "";
    while(next_perm());
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << "\n";
    return 0;
}
