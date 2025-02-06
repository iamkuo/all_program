#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    int prize = 0;
    int finded = -1;
    cin >> a >> b >> c;
    int as[5];
    int bs[5];
    cin >> as[0] >> as[1] >> as[2] >> as[3] >> as[4];
    cin >> bs[0] >> bs[1] >> bs[2] >> bs[3] >> bs[4];
    for(int i=0;i<5;i++)
    {
        if(a == as[i])
        {
            prize += bs[i];
        }
        if(b == as[i])
        {
            prize += bs[i];
        }
        if(c == as[i])
        {
            finded = 1;
            prize -= bs[i];
        }
    }
    if(finded >= 0)
    {
        if(prize > 0)
        {
            cout << prize;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    else
    {
        prize *= 2;
        cout << prize;
        return 0;
    }

}
