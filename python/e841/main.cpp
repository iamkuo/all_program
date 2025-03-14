#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,m,p,q,r,s;
    cin >> n >> m;
    vector<int>coinsStart(n,0),coinsEnd(n,0);
    vector<int>timesStart(n,1),timesEnd(n,1);
    for(int i=0;i<m;i++)
    {
        cin >> p >> q >> r >> s;
        if(r==1)
        {
            coinsStart[p-1] += s;
            if (q<n) coinsEnd[q] += s;
            //for (int j=p-1;j<q;j++) coins[j] += s;
        }
        else
        {
            //for (int j=p-1;j<q;j++) times[j] *= s;
            timesStart[p-1] *= s;
            if (q<n) timesEnd[q] *= s;
        }
    }
    long long int sumCoins = coinsStart[0];
    sumCoins -= coinsEnd[0];
    long long int sumTimes = timesStart[0];
    sumTimes /= timesEnd[0];
    long long int maxValue = sumCoins*sumTimes;
    int maxno=0;
    for (int i=1;i<n;i++)
    {
        sumCoins += coinsStart[i];
        sumCoins -= coinsEnd[i];
        sumTimes *= timesStart[i];
        sumTimes /= timesEnd[i];
        long long int value = sumCoins * sumTimes;
        if(value > maxValue)
        {
            maxno = i;
            maxValue = value;
        }
    }
    cout << maxno+1 << " " << maxValue << endl;

}
