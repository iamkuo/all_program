#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> dat;
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        if(n == 1)
        {
            cin >> n;
            dat.push(n);
        }
        else if(!dat.empty())
        {
            cout << dat.top() << endl;
            dat.pop();
        }
        else
        {
            cout << "empty!" << endl;
        }
    }
}
