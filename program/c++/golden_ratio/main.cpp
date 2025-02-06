#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> squares(n);
    squares[0] = 1;
    squares[1] = 1;
    for(int i=2;i<n;i++)
    {
        squares[i] = squares[i-1]+squares[i-2];
    }
    for(int i=0;i<n;i++)
    {
        cout << squares[i] << endl;
    }
    cout << squares[n-1] << ":" << squares[n-1] + squares[n-1-1];
}
