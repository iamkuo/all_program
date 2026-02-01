#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t,k;
    bool first;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> k;
        vector<int> dat(k);
        vector<int> bitmask(6,1);
        bitmask.insert(bitmask.end(),k-6,0);
        for(int j=0;j<k;j++) cin >> dat[j];
        while(1)
        {
        	first = true;
            for(int j=0;j<k;j++)
            {
                if(dat[j] && bitmask[j])
                {
                    if(first) first = false;
                    else cout << " ";
                    cout << dat[j];
                }
            }
            cout << endl;
            if(!prev_permutation(bitmask.begin(),bitmask.end())) break;
        }

    }
}
