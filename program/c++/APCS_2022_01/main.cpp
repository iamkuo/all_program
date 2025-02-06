#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n];
    int y[n];
    int ans;
    int dis_max = -1;
    int dis_min = 401;
    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i=1;i<n;i++)
    {
        ans = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        if(ans > dis_max)
        {
            dis_max = ans;
        }
        if(ans < dis_min)
        {
            dis_min = ans;
        }
    }
    cout << dis_max << " " << dis_min;
    return 0;
}
