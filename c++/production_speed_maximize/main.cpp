#include<bits/stdc++.h>

using namespace std;

bool machines_sort(int a,int b)
{
    return a>b;
}

bool works_sort(int a,int b)
{
    return a<b;
}


class work
{
public:
    int l = 0;
    int r = 0;
    int w = 0;
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    long long int ans = 0;
    cin >> n >> m;
    int counter = 0;
    work works[m];
    int works_transactions[n];
    for(int i=0;i<n;i++)
    {
        works_transactions[i] = 0;
    }
    int machines[n];
    for(int i=0;i<m;i++)
    {
        cin >> works[i].l;
        cin >> works[i].r;
        cin >> works[i].w;

    }
    for(int i=0;i<n;i++)
    {
        cin >> machines[i];
    }
    sort(machines,machines+n,machines_sort);
    for(int i=0;i<m;i++)
    {
        works_transactions[works[i].l-1] += works[i].w;
        if(works[i].r<n)
        {
            works_transactions[works[i].r] -= works[i].w;
        }
    }
    for(int i=0;i<n;i++)
    {
        counter += works_transactions[i];
        works_transactions[i] = counter;
    }
    sort(works_transactions,works_transactions+n,works_sort);
    for(int i=0;i<n;i++)
    {
        ans += works_transactions[i] * machines[i];
    }
    cout << ans << endl;


}
