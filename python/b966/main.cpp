#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    vector<int> line(10000001,0);
    int n,l,r,minPoint,maxPoint;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> l >> r;
        if (i==0)
        {
            minPoint = l;
            maxPoint = r;
        }else{
            if (l<minPoint) minPoint = l;
            if (r>maxPoint) maxPoint = r;
        }
        line[l] += 1;
        line[r] -= 1;
    }
    int cover = 0;
    int lineLength = 0;
    for(int i=minPoint;i<=maxPoint;i++)
    {
        cover += line[i];
        if(cover > 0)
        {
            lineLength ++;
        }
    }
    cout << lineLength << endl;

}
