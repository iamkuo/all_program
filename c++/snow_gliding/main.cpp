#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n];
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
    }
    int t;
    cin >> t;
    t--;
    if(t+1 == n)
    {
        //cout << "left" << endl;
        while(x[t-1] < x[t] && t > 0)
        {
            t--;
        }
    }
    else if(t == 0)
    {
        //cout << "right" << endl;
        while(x[t+1] < x[t] && t < n-1)
        {
            t++;
        }
    }
    else if(x[t-1]<x[t+1])
    {
        //cout << "left" << endl;
        while(x[t-1] < x[t] && t > 0)
        {
            t--;
        }
    }
    else
    {
        //cout << "right" << endl;
        while(x[t+1] < x[t] && t < n-1)
        {
            t++;
        }
    }
    cout << t+1;
}
