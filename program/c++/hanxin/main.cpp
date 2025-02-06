#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class dat
{
public:
    int a;
    int b;
};

bool dat_sort(dat a,dat b)
{
    return a.a > b.a;
}

int main()
{
    dat ab[3];
    for(int i=0;i<3;i++)
    {
        cin >> ab[i].a;
        cin >> ab[i].b;
    }
    sort(ab,ab+3,dat_sort);
    for (int i=1;i<2000000/ab[0].a;i++)
    {
        int peoples = ab[0].a*i+ab[0].b;
        if(peoples % ab[1].a == ab[1].b && peoples % ab[2].a == ab[2].b)
        {
            cout << peoples << "\n";
            return 0;
        }
    }


}
