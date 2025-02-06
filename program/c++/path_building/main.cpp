#include <bits/stdc++.h>
using namespace std;
class slot
{
public:
    bool pillar=false;
    int line=0;//1=-,2=|,3=+
};
int add_pillar(int n,int m,int r,int c,slot*dat)
{
    int area = 1;
    if (dat[m*r+c].line > 0)
    {
        area = 0;
    }
    dat[m*r+c].pillar = true;
    dat[m*r+c].line = 0;
    //
    //
    //left
    //
    //
    int t=c-1;
    while(dat[m*r+t].pillar == false && t >= 0)
    {
        t--;
    }
    if(t >=0)
    {
        for(int i=c-1;i>t;i--)
        {
            if(dat[m*r+i].line == 0)
            {
                area ++;
                dat[m*r+i].line = 1;
            }
            else if (dat[m*r+i].line == 2)
            {
                dat[m*r+i].line = 3;
            }
        }
    }
    //
    //
    //right
    //
    //
    t=c+1;
    while(dat[m*r+t].pillar == false && t < m)
    {
        t++;
    }
    if(t < m)
    {
        for(int i=c+1;i<t;i++)
        {
            if(dat[m*r+i].line == 0)
            {
                area ++;
                dat[m*r+i].line = 1;
            }
            else if (dat[m*r+i].line == 2)
            {
                dat[m*r+i].line = 3;
            }
        }
    }
    //
    //
    //up
    //
    //
    t=r-1;
    while(dat[m*t+c].pillar == false && t >= 0)
    {
        t--;
    }
    if(t >=0)
    {
        for(int i=r-1;i>t;i--)
        {
            if(dat[m*i+c].line == 0)
            {
                area ++;
                dat[m*i+c].line = 2;
            }
            else if (dat[m*i+c].line == 1)
            {
                dat[m*i+c].line = 3;
            }
        }
    }
    //
    //
    //down
    //
    //
    t=r+1;
    while(dat[m*t+c].pillar == false && t < n)
    {
        t++;
    }
    if(t < n)
    {
        for(int i=r+1;i<t;i++)
        {
            if(dat[m*i+c].line == 0)
            {
                area ++;
                dat[m*i+c].line = 2;
            }
            else if (dat[m*i+c].line == 1)
            {
                dat[m*i+c].line = 3;
            }
        }
    }
    return area;
}
int remove_pillar(int n,int m,int r,int c,slot*dat)
{
    int area = 1;
    dat[m*r+c].pillar = false;
    dat[m*r+c].line = 0;
    //
    //
    //left
    //
    //
    int t=c-1;
    while(dat[m*r+t].pillar == false && t >= 0 && (dat[m*r+t].line == 1 || dat[m*r+t].line == 3))
    {
        if(dat[m*r+t].line == 1)
        {
            dat[m*r+t].line = 0;
            area ++;
        }
        else
        {
            dat[m*r+t].line = 2;
        }
        t--;
    }
    //
    //
    //right
    //
    //
    t=c+1;
    while(dat[m*r+t].pillar == false && t < m && (dat[m*r+t].line == 1 || dat[m*r+t].line == 3))
    {
        if(dat[m*r+t].line == 1)
        {
            dat[m*r+t].line = 0;
            area ++;
        }
        else
        {
            dat[m*r+t].line = 2;
        }
        t++;
    }
    //
    //
    //up
    //
    //
    t=r-1;
    while(dat[m*t+c].pillar == false && t >= 0 && (dat[m*t+c].line == 2 || dat[m*t+c].line == 3))
    {
        if(dat[m*t+c].line == 2)
        {
            dat[m*t+c].line = 0;
            area ++;
        }
        else
        {
            dat[m*t+c].line = 1;
        }
        t--;
    }
    //
    //
    //down
    //
    //
    t=r+1;
    while(dat[m*t+c].pillar == false && t < n && (dat[m*t+c].line == 2 || dat[m*t+c].line == 3))
    {
        if(dat[m*t+c].line == 2)
        {
            dat[m*t+c].line = 0;
            area ++;
        }
        else
        {
            dat[m*t+c].line = 1;
        }

        t++;
    }
    return area;
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int m,n,h;
    int ans=0;
    int max_ans=0;
    cin >> m >> n >> h;
    slot dat[m*n];
    for(int i=0;i<h;i++)
    {
        int r,c,t;
        cin >> r >> c >> t;
        if(t == 0)
        {
            ans += add_pillar(m,n,r,c,dat);

        }
        else
        {
            ans -= remove_pillar(m,n,r,c,dat);
        }
        if(ans > max_ans)
        {
            max_ans = ans;
        }
        /*
        cout << ans << endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dat[n*i+j].pillar)
                {
                    cout << "@";
                }
                if(dat[n*i+j].line > 0)
                {
                    if(dat[n*i+j].line == 1)
                    {
                        cout << "-";
                    }
                    if(dat[n*i+j].line == 2)
                    {
                        cout << "|";
                    }
                    if(dat[n*i+j].line == 3)
                    {
                        cout << "+";
                    }
                }
                if(dat[n*i+j].pillar == false && dat[n*i+j].line == 0)
                {
                    cout << 0;
                }
            }
            cout << endl;

        }
        //*/
    }
    cout << max_ans << endl;
    cout << ans << endl;

    return 0;
}
