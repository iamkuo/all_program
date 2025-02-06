#include <bits/stdc++.h>

using namespace std;

int main()
{
    int order;
    int all_price = 0;
    vector<int> orders(0);
    string menu[9] = {"Medium Wac","WChicken Nugget","Geez Burger","ButtMilk Crispy Chicken","Plastic Toy","German Fries","Durian Slices","WcFurry","Chocolate Sunday"};
    int price[9] = {4,8,7,6,3,2,3,5,7};
    while (true)
    {
        cin >> order;
        if(order == 0)
        {
            break;
        }
        else if(order == 1)
        {
            cin >> order;
            orders.push_back(order);
        }
        else
        {
            cin >> order;
            orders.push_back(order+5);
        }
    }
    for(int i=0;i<orders.size();i++)
    {
        if(orders[i] > 5)
        {
            cout << menu[orders[i]-1] << " " << price[orders[i]-1] << "\n";
            all_price += price[orders[i]-1];
        }
        else
        {
            cout << menu[orders[i]-1] << " " << price[orders[i]-1] << "\n";
            all_price += price[orders[i]-1];
        }
    }
    cout << "Total: " << all_price;

}
