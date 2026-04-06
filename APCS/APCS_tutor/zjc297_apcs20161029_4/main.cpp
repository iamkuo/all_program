#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    string tmp;
    vector<vector<int>> plr(9);
    //0:FO,GO,SO
    //1:1B
    //2:2B
    //3:3B
    //4:HR
    for(int i=0;i<9;i++)
    {
        cin >> a;
        plr[i].resize(a);
        for(int j=0;j<a;j++)
        {
            cin >> tmp;
            if(tmp == "1B") plr[i][j] = 1;
            else if(tmp == "2B") plr[i][j] = 2;
            else if(tmp == "3B") plr[i][j] = 3;
            else if(tmp == "HR") plr[i][j] = 4;
            else plr[i][j] = 0;
        }
    }
    /*
    for(vector<int> v : plr)
    {
        for(int i : v) cout << i << " ";
        cout << "\n";
    }
    */
    int round=0,out=0,goal,score=0,player=0;
    cin >> goal;
    bool field[3] = {false,false,false};
    while(out<goal)
    {
        int hit=plr[player][round];
        if(hit == 0)
        {
            out ++;
            if(out == goal)
            {
                cout << score;
                return 0;
            }
            if(out % 3  == 0)
            {
                field[0] = false;
                field[1] = false;
                field[2] = false;
            }
        }
        else
        {
            for(int i = 2; i >= 0; i--)
            {
                if(field[i])
                {
                    int new_pos = i + hit;
                    field[i] = false;

                    if(new_pos >= 3)  // 得分
                    {
                        score++;
                    }
                    else  // 移動到新壘包
                    {
                        field[new_pos] = true;
                    }
                }
            }
            if(hit < 4) field[hit - 1] = true;
            else score++;
        }
        player++;
        if(player == 9)
        {
            player = 0;
            round++;
        }
    }
    return 0;
}
