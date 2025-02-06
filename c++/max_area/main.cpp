#include <bits/stdc++.h>

using namespace std;

class mark
{
public:
    int h;
    int start;
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    while(cin >> m >> n)
    {
        int dat[m][n];
        int h[m][n];
        vector<mark> marks(n);
        int tmp = 0;
        int max_rect = 0;
        //input,check height
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> dat[i][j];
                if(i == 0)
                {
                    h[i][j] = dat[i][j];
                }
                else
                {
                    if(dat[i][j] == 1)
                    {
                       h[i][j] = h[i-1][j]+1;
                    }
                    else
                    {
                        h[i][j] = 0;
                    }
                }
            }
        }
        /*
        cout << endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << h[i][j] << " ";
            }
            cout << endl;
        }
        */
        for(int i=0;i<m;i++)
        {
            tmp = 0;
            for(int j=0;j<n;j++)
            {
                if(tmp == 0 || h[i][j] > marks[tmp-1].h)
                {
                    marks[tmp].h = h[i][j];
                    marks[tmp].start = j;
                    tmp ++;
                }
                else
                {
                    while(tmp > 0 && marks[tmp-1].h >= h[i][j])
                    {
                        if(marks[tmp-1].h*(j-marks[tmp-1].start) > max_rect)
                        {
                            max_rect = marks[tmp-1].h*(j-marks[tmp-1].start);
                        }
                        tmp --;
                    }
                    marks[tmp].h = h[i][j];
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
        }
        cout << max_rect;
        cout << "\n";
    }
}
