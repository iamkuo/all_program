#include <bits/stdc++.h>
using namespace std;

int h,w,a,b,ans=0;
vector<vector<bool>> grid;

void print_grid()
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
           cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve(int n)
{
    if(n == a)
    {
        ans ++;
        return;
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(grid[i][j]) continue;
            grid[i][j] = true;
            solve(n);
            if((i<h-1) && (!grid[i+1][j]))
            {
                grid[i+1][j] = true;
                solve(n+1);
                grid[i+1][j] = false;
            }
            if((j<w-1) && (!grid[i][j+1]))
            {
                grid[i][j+1] = true;
                solve(n+1);
                grid[i][j+1] = false;
            }
            grid[i][j] = false;
            return;
        }
    }

}

int main()
{
    cin >> h >> w >> a >> b;
    grid.resize(h,vector<bool>(w,false));
    solve(0);
    cout << ans;
    return 0;
}
