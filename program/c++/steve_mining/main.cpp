#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class mineral
{
public:
    int weight,price;
};

bool mineral_sort(mineral a,mineral b)
{
    return a.price > b.price;
}

int main()
{
    int n,m;
    int profit = 0;
    cin >> n >> m;
    mineral minerals[n];
    for(int i=0;i<n;i++)
    {
        cin >> minerals[i].weight >> minerals[i].price;
    }
    sort(minerals,minerals+n,mineral_sort);
    for(int i=0;i<n;i++)
    {
        if(m-minerals[i].weight >= 0)
        {
            profit += minerals[i].weight*minerals[i].price;
            m -= minerals[i].weight;
        }
        else
        {
            cout << profit + minerals[i].price*m;
            return 0;
        }
    }
    cout << profit;

}
