
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k,ki,m,x;
    string command;
    cin >> t;
    for(int i=0;i<t;i++)//第幾組測資
    {
        cout << "Line #" << i+1 << endl;
        cin >> n;
        map<int,int> groups;//每一個人是哪一團的
        list<int> line;//目前隊伍
        vector<list<int>::iterator> end_people(n,line.end());//每一團的最後一個人的位置(從0開始)
        for(int j=0;j<n;j++)//第幾團
        {
            cin >> k;
            for(int m=0;m<k;m++)//第幾個
            {
                cin >> ki;
                groups[ki] = j;
            }
        }
        cin >> m;
        for(int j=0;j<m;j++)
        {
            cin >> command;
            if(command[0] == 'E')
            {
                cin >> x;
                //auto& end_person_pos = end_people[groups[x]]; //list<int>::iterator
                if(groups.find(x) == groups.end()|| end_people[groups[x]] == line.end())//同一組內沒有在隊伍中的人或他是可憐邊緣人
                {
                    line.push_back(x);
                    //for(int k : line) cout << k << " ";
					//cout << endl;
                    if(!(groups.find(x) == groups.end())) end_people[groups[x]] = prev(line.end());
                }
                else//插隊
                {
                    line.insert(next(end_people[groups[x]]),x);
                    //for(int k : line) cout << k << " ";
					//cout << endl;
                    advance(end_people[groups[x]],1);
                }
            }
            else
            {
                cout << *line.begin() << endl;
                line.pop_front();
                //for(int k : line) cout << k << " ";
				//cout << endl;
            }
        }
    }
    return 0;
}