#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string data[n];
    int int_data[n][n];
    for(int i=0;i<n;i++)
    {
        cin >> data[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(data[i][j] == 'O')
            {
                int_data[i][j] = 0;
            }
            else
            {
                int_data[i][j] = 1;
            }
        }
    }
    int list_sum;
    for(int i=0;i<n;i++)
    {

    }
    if(n%2==0)
    {
        if(list_sum(int_data,n) != (n*n)/2)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    else
    {
        if(list_sum(int_data,n) != ((n*n)/2)+1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    int so,sx,suml2r,sumr2l = 0;
    for(int i=0;i<n;i++)
    {
        int sumcol = 0;
        int sumrow = 0;
        for(int j=0;j<n;i++)
        {
            sumcol += int_data[j][i];
            sumrow += int_data[i][j];
        }
        if(sumcol == 0) so++;
        if(sumcol == n) sx++;
        if(sumrow == 0) so++;
        if(sumrow == n) sx++;
        suml2r += int_data[i][i];
        sumr2l += int_data[i][n-1-i];
    }
    if(suml2r == 0) so++;
    if(suml2r == n) sx++;
    if(sumr2l == 0) so++;
    if(sumr2l == n) sx++;
}
