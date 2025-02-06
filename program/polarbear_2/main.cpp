#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x<=1000)
    {
        cout << x-1 << " ";
        cout << 1 << endl;
    }
    else
    {
        cout << 1000 << " ";
        cout << x-1000 << endl;
    }
}
