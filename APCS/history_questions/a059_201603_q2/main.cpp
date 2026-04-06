#include <bits/stdc++.h>
using namespace std;

int grid[11][11];
int tmp[11][11];
int r,c,m,k,tmp_r;

void flip()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) tmp[r-i-1][j] = grid[i][j];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) grid[i][j] = tmp[i][j];
    }
}

void turn()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) tmp[c-1-j][i] = grid[i][j];
    }
    tmp_r = r;
    r = c;
    c = tmp_r;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) grid[i][j] = tmp[i][j];
    }
}

int main()
{
    int k[11];
    cin >> r >> c >> m;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) cin >> grid[i][j];
    }
    for(int i=0;i<m;i++) cin >> k[i];
    for(int i=m-1;i>=0;i--)
    {
        switch(k[i])
        {
        case 0:
            turn();
            break;
        case 1:
            flip();
            break;
        }
    }
    cout << r << " " << c << "\n";
    for(int i=0;i<r;i++)
    {
        cout << grid[i][0];
        for(int j=1;j<c;j++) cout << " " << grid[i][j];
        cout << "\n";
    }
    return 0;
}
