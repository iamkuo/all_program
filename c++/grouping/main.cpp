#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int p;
    int p_digit = 0;
    int power_sum = 0;
    int max_power = -1;
    int max_power_number;
    int number_now = 1;
    vector<int> p_slice;
    cin >> n >> p;
    while(p > 0)
    {
        p_slice.push_back(p % 10);
        p /= 10;
        p_digit ++;
    }
    int now = 0;
    for(int i=0;i<p_digit;i++)
    {
        now ++;
        power_sum += p_slice[i];
        //cout << now << " " << power_sum << " " << number_now << " " << p_slice[i] << endl;
        if(now == n || i == p_digit-1)
        {
            if(power_sum >= max_power)
            {
                max_power = power_sum;
                max_power_number = number_now;
            }
            power_sum = 0;
            number_now ++;
            now = 0;
        }
    }
    cout << max_power_number << " " << max_power;
}

