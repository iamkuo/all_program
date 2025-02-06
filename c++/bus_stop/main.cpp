#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int b,p;
    int tmp;
    int counter=0;
    cin >> b;
    cin >> p;
    vector<int> up(p);
    vector<int> down(p);
    vector<int> dat(b+1,0);
    for (int i=0;i<p;i++)
    {
        cin >> up[i];
        cin >> down[i];
        if(up[i]>down[i])
        {
            tmp = up[i];
            up[i] = down[i];
            down[i] = tmp;
        }
        dat[up[i]] ++;
        if(down[i] != b)
        {
            dat[down[i]+1] --;
        }
    }
    int min_people=dat[1];
    int min_people_station=1;
    int max_people=dat[1];
    int max_people_station=1;
    for (int i=1;i<=b;i++)
    {
        counter += dat[i];
        dat[i] = counter;
        if(dat[i]>=max_people)
        {
            max_people = dat[i];
            max_people_station = i;
        }
        else if(dat[i]<min_people)
        {
            min_people = dat[i];
            min_people_station = i;
        }
    }

    cout << min_people_station << " ";
    cout << max_people_station;

}
