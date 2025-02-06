#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int enter[3];
    int sum[9];
    int most_number_amount = -1;
    for(int i=0;i<9;i++)
    {
        sum[i] = 0;
    }
    for(int i=0;i<3;i++)
    {
        cin >> enter[i];
        sum[enter[i]-1] ++;
    }
    for(int i=0;i<9;i++)
    {
        if(sum[i] > most_number_amount)
        {
            most_number_amount = sum[i];
        }
    }
    cout << most_number_amount;
    for(int i=8;i>=0;i--)
    {
        if(sum[i] > 0)
        {
            cout << " " << i+1;
        }
    }
}
