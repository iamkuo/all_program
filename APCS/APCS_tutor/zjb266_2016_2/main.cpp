#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,c,m;
    cin >> r >> c >> m;
    vector<vector<int>> *grid_a = new vector<vector<int>>(r,vector<int>(c));
    vector<vector<int>> *grid_b;
    vector<int> todo(m);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) cin >> (*grid_a)[i][j];
    }
    for(int i=0;i<m;i++) cin >> todo[i];
    for(int i=m-1;i>=0;i--)
    {
        if(todo[i] == 0)
        {
            //cout << "rotating\n";
            grid_b = new vector<vector<int>>(c,vector<int>(r));
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    /*
                    for(vector<int> &i : (*grid_a))
                    {
                        for(int &j : i) cout << j << " ";
                        cout << "\n";
                    }
                    */
                    //cout << i << " " << j << " goto " << j << " " << r-i-1 << "\n";
                    (*grid_b)[c-j-1][i] = (*grid_a)[i][j];
                    //cout << i << " " << j << " goto " << j << " " << r-i-1 << "\n";
                }
            }
            swap(r,c);
        }
        else
        {
            //cout << "flipping\n";
            grid_b = new vector<vector<int>>(r,vector<int>(c));
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++) (*grid_b)[r-i-1][j] = (*grid_a)[i][j];
            }
        }
        grid_a = grid_b;
        /*
        for(vector<int> &i : (*grid_a))
        {
            for(int &j : i) cout << j << " ";
            cout << "\n";
        }
        */
    }
    cout << r << " " << c << "\n";
    for(vector<int> &i : (*grid_a))
    {
        cout << i[0];
        for(int j=1;j<i.size();j++) cout << " " << i[j];
        cout << "\n";
    }
    return 0;
}
