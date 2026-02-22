#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define tiii tuple<int,int,int>
#define f first
#define s second
using namespace std;

bool cmp_p(tiii &a,tiii &b) {return get<0>(a) < get<0>(b);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k=0;//how many rooms are there now
    cin >> n;
    vector<tiii> people(n);//(come,leave,id)
    vector<int> ans(n);//room id of all people
    for(int i=0;i<n;i++)
    {
        cin >> get<0>(people[i]) >> get<1>(people[i]);
        get<2>(people[i]) = i;
    }
    sort(people.begin(),people.end(),cmp_p);
    priority_queue<pii,vector<pii>,greater<pii>> rooms;
    //(last occupied time,id)
    for(int i=0;i<n;i++)
    {
        if(rooms.empty() || rooms.top().f >= get<0>(people[i]))
        {
            k++;
            rooms.push(mp(get<1>(people[i]),k));
            ans[get<2>(people[i])] = k;
        }
        else
        {
            pii next_room = rooms.top();
            rooms.pop();
            rooms.push(mp(get<1>(people[i]),next_room.s));
            ans[get<2>(people[i])] = next_room.s;
        }
    }
    cout << k << "\n";
    for(int i:ans) cout << i << " ";
    return 0;
}
