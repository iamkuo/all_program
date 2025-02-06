#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,counter=0;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin >> h[i];
    }
    for (int i=0;i<n;i++)
    {
        if(h[i] == 0)
        {
            if(i == 0)
            {
                counter += h[1];
            }
            else if(i == n-1)
            {
                counter += h[n-2];
            }
            else
            {
                if(h[i-1] < h[i+1])
                {
                    counter += h[i-1];
                }
                else
                {
                    counter += h[i+1];
                }
            }

        }
    }
    cout << counter;

}
