#include <bits/stdc++.h>
using namespace std;

bool reserved[8][8],valid;
int pos[8]; // each row
int ans = 0;

int abs(int x)
{
    if(x >= 0) return x;
    return -x;
}

bool check(int y1,int y2,int x2)//check if (y1,pos[y1]),(y2,x2) interfere
{
    return !(pos[y1] == x2 || abs(x2-pos[y1]) == y2-y1);
}
void solve(int n)
{
    if(n == 8)
    {
        ans ++;
        return;
    }
    for(int i=0;i<8;i++)//attempt to place at (n,i)
    {
        if(reserved[n][i]) continue;
        valid = true;
        for(int j=0;j<n;j++)//checking y=0~n-1
        {
            if(!check(j,n,i))
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
            pos[n] = i;
            solve(n+1);
        }
    }
}

int main()
{
    string tmp;
    for(int i=0;i<8;i++)
    {
        cin >> tmp;
        for(int j=0;j<8;j++)
        {
            if(tmp[j] == '.') reserved[i][j] = false;
            else reserved[i][j] = true;
        }
    }
    solve(0);
    cout << ans;
    return 0;
}
