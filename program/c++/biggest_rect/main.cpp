#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int max_h = 0;
    int max_rect = 0;
    int rect_tmp = 0;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin >> h[i];
        if(h[i] > max_h)
        {
            max_h = h[i];
        }
    }
    for(int i=0;i<max_h;i++)
    {
        rect_tmp = 0;
        for(int j=0;j<n;j++)
        {
            if(h[j] >= i)
            {
                //cout << j << endl;
                rect_tmp += i;
                if(rect_tmp > max_rect)
                {
                    max_rect = rect_tmp;
                }
            }
            else
            {
                rect_tmp = 0;
            }
        }
        //cout << endl;
    }
    cout << max_rect;

}
