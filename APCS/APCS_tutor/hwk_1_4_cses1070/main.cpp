#include <iostream>

using namespace std;

int main()
{
    int n,i;
    cin >> n;
    if(n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    i = 2;
    while(i <= n)
    {
        cout << i << " ";
        i += 2;
    }
    i = 1;
    while(i <= n)
    {
        cout << i << " ";
        i += 2;
    }
    return 0;
}
