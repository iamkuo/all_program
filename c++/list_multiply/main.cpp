#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
int positive_only(int x)
{
    if(x>=0)
    {
        return x;
    }
    else
    {
        return 0;
    }
}
*/

int axb(int n,int m,int* n_list,int* m_list)
{
    int brutal_ans = 0;
    int max_ans = n_list[0]*m_list[0];
    for(int i=0;i<=n+m-2;i++)
    {
        bool first = true;
        for(int j=0;j<m;j++)
        {
            int pos = i-(m-1)+j;
            if(pos>=0 && pos<n)
            {
                if(first)
                {
                    first = false;
                    brutal_ans = n_list[pos]*m_list[j];
                    max_ans = max(brutal_ans,max_ans);
                }
                else
                {
                    brutal_ans = max(n_list[pos]*m_list[j],brutal_ans+n_list[pos]*m_list[j]);
                    max_ans = max(brutal_ans,max_ans);
                }
            }
        }
    }
    return max_ans;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int n_list[n];
    int m_list[m];
    for(int i=0;i<n;i++)
    {
        cin >> n_list[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> m_list[i];
    }

    int max_ans = axb(n,m,n_list,m_list);
    int m_reverse[m];
    for(int i=0;i<m;i++)
    {
        m_reverse[i] = m_list[m-i-1];
    }

    cout << max(max_ans,axb(n,m,n_list,m_reverse));

    return 0;
}
