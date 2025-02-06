#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int win(int f,int y)
{
    if(f == y)
    {
        return 0;
    }
    else if(f == 0 && y == 2 || f == 2 && y == 5 || f == 5 && y == 0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int main()
{
    int f;
    cin >> f;
    int n;
    cin >> n;
    int y[n];
    int plr_ans;
    int ans;
    for(int i=0;i<n;i++)
    {
        cin >> y[i];
    }
    cout << f;
    //cout << f << y[0] << endl;
    ans = win(f,y[0]);
    if(ans == 1)
    {
        cout << " : Won at round 1";
        return 0;
    }
    else if(ans == 2)
    {
        cout << " : Lost at round 1";
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        if(i >= 2)
        {
            if(y[i-1] == y[i-2])
            {
                if(y[i-1] == 0)
                {
                    plr_ans = 5;
                }
                else if(y[i-1] == 2)
                {
                    plr_ans = 0;
                }
                else
                {
                    plr_ans = 2;
                }
            }
            else
            {
                plr_ans = y[i-1];
            }
        }
        else
        {
            plr_ans = y[i-1];
        }
        cout << " " << plr_ans;
        //cout << plr_ans << y[i] << endl;
        ans = win(plr_ans,y[i]);
        if(ans == 1)
        {
            cout << " : Won at round " << i+1;
            return 0;
        }
        else if(ans == 2)
        {
            cout << " : Lost at round " << i+1;
            return 0;
        }
    }
    cout <<" : Drew at round " << n;
    return 0;
}
