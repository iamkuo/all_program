#include <bits/stdc++.h>
using namespace std;

int dict=1,n,m,r,k,t;
vector<int> students; //(i+1)/r+1=class
vector<int> ans; // the id of each student

//(last not selected, curr amount of people)
void dfs(int last,int cnt)
{
    if(cnt == k)
    {
        dict++;
        if(dict == t)
        {
            for(int i : students) cout << i << " ";
            return;
        }
        return;
    }
    bool ok;
    int quota;
    for(int i = last;i<students.size();i++)
    {
        ok = true;
        quota = 2;
        for(int j=0;j<cnt;j++)
        {
            if(students[ans[j]] == students[i])
            {
                ok = false;
                break;
            }
        }
        if(!ok) break;
        for(int j=0;j<cnt;j++)
        {
            if(ans[j] == students) //???
        }
        if(!ok) break;

        dfs(i+1,cnt+1);//select i
    }
}

int main()
{
    cin >> n >> m >> r >> k >> t;
    students.resize(m*r);
    ans.resize(k,-1);
    for(int i=0;i<m*r;i++) cin >> students[i];
    dfs(0,0);
    return 0;
}
