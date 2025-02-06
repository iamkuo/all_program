#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int r,c,n;
class stone
{
public:
    int x;
    int y;
    char type;
};
int main()
{
    int left_x[5] = {0,2,1,2,1};
    cin >> r >> c >> n;
    //cout << c;
    int dat[r][c];
    int garbage = 0;
    int space = 0;
    bool in_sucess = true;
    stone stones[n];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            dat[i][j] = 0;
            //cout << dat[i][j];
        }
        //cout << endl;
    }
    for(int i=0;i<n;i++)
    {
        in_sucess = true;
        cin >> stones[i].type >> stones[i].y;
        stones[i].type -= 'A';
        stones[i].x = c-1;
        while(true)
        {
            //cout << "in " << stones[i].x-left_x[stones[i].type] << endl;
            if(stones[i].x - left_x[stones[i].type] < 0) break;
            if(stones[i].type == 0 && (dat[stones[i].y][stones[i].x] != 0 || dat[stones[i].y+1][stones[i].x] != 0 || dat[stones[i].y+2][stones[i].x] != 0 || dat[stones[i].y+3][stones[i].x] != 0)) {
                //cout << "A no" << endl;
                in_sucess = false;
                break;
            }
            else if(stones[i].type == 1 && (dat[stones[i].y][stones[i].x-2] != 0 || dat[stones[i].y][stones[i].x-1] != 0 || dat[stones[i].y][stones[i].x] != 0)) {
                //cout << "B no " << endl;
                in_sucess = false;
                break;
            }
            else if(stones[i].type == 2 && (dat[stones[i].y][stones[i].x-1] != 0 || dat[stones[i].y+1][stones[i].x-1] != 0 || dat[stones[i].y][stones[i].x] != 0 || dat[stones[i].y+1][stones[i].x] != 0)) {
                //cout << "C no" << endl;
                in_sucess = false;
                break;
            }
            else if(stones[i].type == 3 && (dat[stones[i].y][stones[i].x] != 0 || dat[stones[i].y+1][stones[i].x-2] != 0 || dat[stones[i].y+1][stones[i].x-1] != 0 || dat[stones[i].y+1][stones[i].x] != 0)) {
                //cout << "D no" << endl;
                in_sucess = false;
                break;
            }
            else if(stones[i].type == 4 && (dat[stones[i].y][stones[i].x] != 0 || dat[stones[i].y+1][stones[i].x-1] != 0 || dat[stones[i].y+1][stones[i].x] != 0 || dat[stones[i].y+2][stones[i].x-1] != 0 || dat[stones[i].y+2][stones[i].x] != 0 )) {
                //cout << "E no" << endl;
                in_sucess = false;
                break;
            }

            stones[i].x--;
        }
        stones[i].x ++;
        if(in_sucess == true || (in_sucess == false && stones[i].x <= c-1))
        {
            if(stones[i].type == 0) dat[stones[i].y][stones[i].x] = dat[stones[i].y+1][stones[i].x] = dat[stones[i].y+2][stones[i].x] =dat[stones[i].y+3][stones[i].x] = 1;
            else if(stones[i].type == 1) dat[stones[i].y][stones[i].x-2] = dat[stones[i].y][stones[i].x-1] = dat[stones[i].y][stones[i].x] = 1;
            else if(stones[i].type == 2) dat[stones[i].y][stones[i].x-1] = dat[stones[i].y+1][stones[i].x-1] = dat[stones[i].y][stones[i].x] = dat[stones[i].y+1][stones[i].x] = 1;
            else if(stones[i].type == 3) dat[stones[i].y][stones[i].x] = dat[stones[i].y+1][stones[i].x-2] = dat[stones[i].y+1][stones[i].x-1] = dat[stones[i].y+1][stones[i].x] = 1;
            else if(stones[i].type == 4) dat[stones[i].y][stones[i].x] = dat[stones[i].y+1][stones[i].x-1] = dat[stones[i].y+2][stones[i].x-1] = dat[stones[i].y+1][stones[i].x] = dat[stones[i].y+2][stones[i].x] = 1;
        }
        else garbage ++;
        /*
        for(int j=0;j<r;j++)
        {
            for(int k=0;k<c;k++)
            {
                cout << dat[j][k] << " ";
            }
            cout << endl;
        }
        */
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(dat[i][j] == 0)
            {
                space ++;
            }
        }
    }
    cout << space << " " << garbage;
    return 0;
}
