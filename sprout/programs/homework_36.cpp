#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int t,n;
    queue<int> dat;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        if(n == 1)
        {
            cin >> n;
            dat.push(n);
        }
        else if(dat.empty()) cout << "empty!" << endl;
        else
        {
            cout << dat.front() << endl;
            dat.pop();
        }
    }
}
