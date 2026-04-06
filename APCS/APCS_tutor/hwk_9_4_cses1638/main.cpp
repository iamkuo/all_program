#include <bits/stdc++.h>
using namespace std;

bool check(int x,int y) {return (x>=0) && (y>=0);}

int main()
{
    int n;
    string tmp;
    cin >> n;
    vector<vector<long long>> grid(n,vector<long long>(n,0));
    grid[0][0] = 1;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        for(int j=0;j<n;j++)
        {
            if(tmp[j] == '.')
            {
                if(check(i-1,j) && grid[i-1][j] != -1) grid[i][j] += grid[i-1][j];
                if(check(i,j-1) && grid[i][j-1] != -1) grid[i][j] += grid[i][j-1];
            }
            else grid[i][j] = -1;
            if(grid[0][0] == -1)
            {
                cout << 0;
                return 0;
            }
            grid[i][j] %= (int)(1e9+7);
        }
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j : grid[i]) cout << j << " ";
        cout << "\n";
    }
    */
    cout << ((grid[n-1][n-1] < 0) ? 0 : grid[n-1][n-1]);
    return 0;
}
