#include <iostream>

using namespace std;



int main()
{
    int r,c;
    int bomb_finded = 0;
    bool miss;
    int bomb_not_find = 0;
    cin >> r >> c;
    int dat[r][c];
    for (int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> dat[i][j];
            //cout << dat[i][j] << " ";
        }
        //cout << "\n";
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            //cout << i << " " << j << endl;
            if(dat[i][j] == 5)
            {
                for(int k=i-1;k<=i+1;k++)
                {
                   for(int l=j-1;l<=j+1;l++)
                    {
                        if(k == i && l == j || k < 0 || k >= r || l < 0 || l >= c)
                        {
                            continue;
                        }
                        if(dat[k][l] >= 5)
                        {
                            dat[i][j] = 6;
                            dat[k][l] = 6;

                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            //cout << i << " " << j << endl;
            if(dat[i][j] == 1)
            {
                miss = true;
                for(int k=i-1;k<=i+1;k++)
                {
                    for(int l = j-1;l<= j+1;l++)
                    {
                        if(k == i && l == j || k < 0 || k >= r || l < 0 || l >= c)
                        {
                            continue;
                        }
                        if(dat[k][l] == 5)
                        {
                            miss = false;
                            bomb_finded ++;
                            break;
                        }
                    }
                    if(miss == false)
                    {
                        break;
                    }
                }
                if(miss == true)
                {
                    bomb_not_find ++;
                }
            }
        }
    }
    cout << bomb_finded << " " << bomb_not_find;
}
