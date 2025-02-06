#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class box
{
public:
    int space,price;
};

int scan(int start,int weight_left,int cargo_number,vector<box> cargos)
{
    //cout << start << " " << weight_left << "\n";
    int max_profit = 0;
    int tmp;
    for(int i=start;i<cargo_number;i++)
    {
        if(weight_left - cargos[i].space >= 0)
        {
            tmp = cargos[i].price+scan(i+1,weight_left-cargos[i].space,cargo_number,cargos);
            max_profit = max(max_profit,tmp);
        }
        else
        {
            break;
        }
    }
    return max_profit;
}

bool cargo_sort(box a,box b)
{
    return a.space < b.space;
}

int main()
{

    int k;
    vector<box> cargos;
    while(cin >> k)
    {
        cargos.clear();
        cargos.resize(k);
        for(int i=0;i<k;i++)
        {
            cin >> cargos[i].space >> cargos[i].price;
        }
        sort(cargos.begin(),cargos.end(),cargo_sort);
        //cout << "ok" << endl;
        cout << scan(0,100,k,cargos) << "\n";
    }

}
