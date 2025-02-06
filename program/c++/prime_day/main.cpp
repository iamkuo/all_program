#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int number)
{
    for(int i=2;i*i<number;i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int d;
    bool prime = true;
    int now = 10;
    cin >> d;
    vector<int> dat(d);
    for(int i=0;i<d;i++)
    {
        cin >> dat[i];
    }
    for(int i=0;i<d;i++)
    {
        now = 10;
        prime = true;
        for(int j=0;j<8;j++)
        {
            if(not is_prime(dat[i] % now))
            {
                prime = false;
                break;
            }
            now *= 10;
        }
        if(prime)
        {
            cout << dat[i] << " is a Prime Day!" << endl;
        }
        else
        {
            cout << dat[i] << " isn't a Prime Day!" << endl;
        }

    }
}
