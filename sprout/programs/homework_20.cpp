using namespace std;
#include <iostream>
#include <list>
#include <vector>
#include <numeric>

void swap(int& a,int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int n,m,t,x,y;
    cin >> n >> m;
    y = n;
    vector<int> leaderboard(n+1);//第n名幾號
    vector<int> ranking(n+1);//第n號幾名，-1=gg
    iota(leaderboard.begin(),leaderboard.end(),1);
    iota(ranking.begin()+1,ranking.end(),1);
    for(int i=0;i<m;i++)
    {
        cin >> t >> x;
        if(t)
        {
        	/*
            swap(leaderboard[ranking[x]],leaderboard[ranking[x]-1]);
            ranking[x] --;//超過減一名
            ranking[leaderboard[x]] ++;
            */
            int pos = ranking[x]; // 玩家x的當前名次
			if (pos > 1) {        // 如果玩家x不是第一名
			    swap(leaderboard[pos], leaderboard[pos - 1]);
			    ranking[leaderboard[pos]]++;
			    ranking[leaderboard[pos - 1]]--;
			}
        }
        else
        {
        	/*
            leaderboard.erase(leaderboard.begin() + ranking[x]);
            y--;
            for(int j=x;j<=y;j++) ranking[leaderboard[j]]--;
            */
            int pos = ranking[x]; // 玩家x的當前名次
			if (pos != -1)
			{      // 如果玩家x尚未被淘汰
			    leaderboard.erase(leaderboard.begin() + pos);
			    ranking[x] = -1;
			    for (int j = pos; j < leaderboard.size(); j++) {
			        ranking[leaderboard[j]]--;
			    }
			}
        }
    }
    for (int i = 1; i < leaderboard.size(); i++)
    {
    	cout << leaderboard[i] << " ";
    }
	cout << endl;

    return 0;
}
