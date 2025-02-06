#include <iostream>

using namespace std;

int main()
{
    int n;
    int first_fence = -1;
    int last_fence = -1;
    int ans = 0;
    cin >> n;
    int land[n];
    for(int i=0;i<n;i++)
    {
        cin >> land[i];
    }
    for(int i=0;i<n;i++)
    {
        if(land[i] == 1)
        {
            first_fence = i;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(land[i] == 1)
        {
            last_fence = i;
        }
    }
    for(int i=first_fence;i<=last_fence;i++)
    {
        if(land[i] == 0 && land[i-1] != 9 && land[i+1] != 9)
        {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
