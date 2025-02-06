using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
class point
{
    public:
        int value;
        int index;

};
int halfSearch(vector<point> data,int left,int right,int searchValue)
{
    if(left > right)
    {
        return -1;
    }
    int mid = (left+right)/2;
    if (data[mid].value > searchValue)
    {
        return halfSearch(data,left,mid-1,searchValue);
    }
    else if(data[mid].value < searchValue)
    {
        return halfSearch(data,mid+1,mid,searchValue);
    }
    else
    {
        return mid;
    }
}
bool comp(point a,point b)
{
    return a.value<b.value;
}

int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    vector<point> dat(n);
    vector<int> question(k);
    for(int i=0;i<n;i++)
    {
        cin >> dat[i].value;
        dat[i].index = i;

    }
    for(int i=0;i<k;i++)
    {
        cin >> question[i];
    }
    sort(dat.begin(),dat.end(),comp);
    for(int i=0;i<k;i++)
    {
        int found = halfSearch(dat,0,n-1,question[i]);

        if(found >= 0)
        {
            cout << found+1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
