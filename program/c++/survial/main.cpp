#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    int w[n];
    int target_location = 0;
    for(int i=0;i<n;i++)
    {
        cin >> h[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> w[i];
    }
    for(int i=0;i<n;i++)
    {
        if(h[i]*w[i] < h[target_location]*w[target_location])
        {
            target_location = i;
        }
    }
    cout << h[target_location] << " " << w[target_location];
}
