using namespace std;
#include <iostream>

int a[1001];
bool b[1001];//true:big false:small
int n,q,i,x;

int duck_db(int y)
{
    int db = a[y];
    if(y == 0 || y == n+1) return 0;
    if(y-1 > 0 && b[y-1]) db *= 2;
    if(y+1 < n+1 && b[y+1]) db *= 2;
    return db;
}

int main()
{
    cin >> n >> q;
    for(i=1;i<=n;i++) cin >> a[i];
    for(i=1;i<=n;i++) cin >> b[i];
    for(i=0;i<q;i++)
    {
        cin >> x;
        cout << duck_db(x-1)+duck_db(x)+duck_db(x+1) << endl;
    }
    return 0;
}