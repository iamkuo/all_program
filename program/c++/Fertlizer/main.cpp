#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int s,e,a;
    int next_day_add = 0;
    cin >> s >> e >> a;
    for(int i=1;i<100;i++)
    {
        s += next_day_add;
        next_day_add = 0;
        if(s >= e)
        {
            cout << i;
            return 0;
        }
        if(i%11 == 0)
        {
            a--;
            if(a == 0)
            {
                break;
            }
        }
        else if(i > 2 && (i % 8 == 1 || i % 8 == 2))
        {
            continue;
        }
        else if(i % 3 == 0)
        {
            cout << s << " magic" << endl;
            next_day_add = floor(s/3*1.0);
        }
        else
        {
            cout << s << endl;
            next_day_add = floor(s/10*1.0);
        }
        i++;
    }
    cout << "unsalable";
}
