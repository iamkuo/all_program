#include <iostream>

using namespace std;

class server{
public:
    int locate;
    int flow[50];
};

int calprice(int cityN,int city,int *TQ)
{
    int price=0;
    for(int i=0;i<cityN;i++)
    {
        if(i==city) price += TQ[i];
        else
        {
            if(TQ[i]>1000) price += (3000+(TQ[i]-1000)*2);
            else price += TQ[i]*3;
        }
    }

    return price;
}

int main()
{
    int n,m,k;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    server pc[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> pc[i].flow[j];
        }
    }
    int minprice;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> pc[j].locate;
        }

        int price = 0;
        for(int j=0;j<m;j++)
        {
            int totalQ[m];
            for(int jj=0;jj<m;jj++) totalQ[jj] = 0;
            for(int jj=0;jj<n;jj++)
            {
                if (pc[jj].locate == j)
                {
                    for(int j3=0;j3<m;j3++) totalQ[j3] += pc[jj].flow[j3];
                }
            }
            price += calprice(m,j,totalQ);
        }
        if(i==0) minprice = price;
        else
        {
            if(price<minprice) minprice = price;
        }
    }
     cout << minprice << endl;


}
