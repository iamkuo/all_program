#include <bits/stdc++.h>

class mark
{
public:
    int h;
    int start;
};

using namespace std;

int main()
{
    int n;
    int h;
    int tmp = 0;
    int max_rect = 0;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<mark> marks(n);
    for(int i=0;i<n;i++)
    {
        cin >> h;
        if(i == 0 || h > marks[tmp-1].h)
        {
            marks[tmp].h = h;
            marks[tmp].start = i;
            tmp ++;
        }
        else
        {
            while(tmp > 0 && marks[tmp-1].h >= h)
            {
                if(marks[tmp-1].h*(i-marks[tmp-1].start) > max_rect)
                {
                    max_rect = marks[tmp-1].h*(i-marks[tmp-1].start);
                }
                tmp --;
            }
            marks[tmp].h = h;
            tmp ++;
        }
    }
    while(tmp > 0)
    {
        if(marks[tmp-1].h*(n-marks[tmp-1].start) > max_rect)
        {
            max_rect = marks[tmp-1].h*(n-marks[tmp-1].start);
        }
        tmp --;
    }
    cout << max_rect;
}
