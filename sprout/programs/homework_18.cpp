#include<iostream>
#include <stack>
using namespace std;

int main()
{
    int t,n,dat;
	bool possible;
    int idx;//已經運了幾台車出去
    cin >> t;
    for(int i=0;i<t;i++)
    {
    	possible = true;
    	stack<int> mid_station;
        idx = 1;
        mid_station.push(1);
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> dat;
            while(mid_station.empty() || mid_station.top() != dat)
            {
                if(idx == n)
                {
                	cin.ignore(1000000,'\n');
                    possible = false;
                    break;
                }
                idx ++;
                mid_station.push(idx);
                //cout << "pushed" << idx << endl;
            }
            if(!possible) break;
            //cout << "poped" << mid_station.top() << endl;
            mid_station.pop();
        }
        if(possible) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}