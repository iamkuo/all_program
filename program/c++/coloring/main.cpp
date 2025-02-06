#include <iostream>

using namespace std;

int mySort(int i,int value,int* sorted,int* pos)
{
    int k=i;
    while (i>0)
    {
        if(value > sorted[i-1])
        {
            sorted[i] = sorted[i-1];
            pos[i] = pos[i-1];
            i--;
        }
        else
        {
            break;
        }
    }
    sorted[i] = value;
    pos[i] = k;
    return 0;
}


int main()
{
    int length = 0;
    int dat[length];
    int small_to_big[length];
    int ans = 0;
    int color[length] = {0};
    int pos[length] = {0};
    cin >> length;
    for(int i=0;i<length;i++)
    {
        cin >> dat[i];
    }
    for(int i=0;i<length;i++)
    {
        mySort(i,dat[i],small_to_big,pos);
    }
    int pp,counter,sumGreen,sumRed = 0;
    while(counter < length)
    {
        if(small_to_big[pp] < 0) break;
        int g=0;
        if(pos[pp]-1 >=0 && color[pos[pp]-1] == 1) g=1;
        if(pos[pp]+1 < length && color[pos[pp]+1] == 1) g=1;
        if(g==0)
        {
            color[pos[pp]] == 1;
            sumGreen += small_to_big[pp];
        }
    }


}
