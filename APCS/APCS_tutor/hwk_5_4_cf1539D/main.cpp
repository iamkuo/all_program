#include <bits/stdc++.h>
#define pll pair<long long,long long>
#define f first
#define s second
using namespace std;

bool cmp(pll &a, pll &b) {return a.s > b.s;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pll> products(n);//(amount,discount minimum)
    for(int i=0;i<n;i++) cin >> products[i].f >> products[i].s;
    sort(products.begin(),products.end(),cmp);
    int l=0;
    //the product with the biggest b that hasn't been completely bought
    int r=n-1;
    //the product with the smallest b that hasn't been completely bought
    long long curr=0,ans=0;
    while(l <= r)
    {
        if (curr >= products[r].s)
        {
            ans += products[r].f;
            curr += products[r].f;
            r--;
        }
        else
        {
            long long buy = min(products[r].s - curr, products[l].f);
            ans += buy * 2;
            products[l].f -= buy;
            curr += buy;
            if (products[l].f == 0) l++;
        }
    }
    cout << ans;
    return 0;
}
