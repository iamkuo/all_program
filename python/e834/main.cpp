#include <iostream>

using namespace std;

int main()
{
    int many;
    int now = 0;
    cin >> many;
    int dat[1001];
    while (cin >> dat[now])
    {
        if (dat[now] == 0)
        {
            break;
        }
        else
        {
            now ++;
        }
    }
    now = 0;
    while (dat[now] != 0)
    {
        if (dat[now] % many == 0 && dat[now] > many)
        {
            //cout << "case 1" << "\n";
            cout << dat[now]/many << "\n";
        }
        else
        {
            //cout << "case 2" << "\n";
            cout << many-(dat[now] % many) << "\n";
        }
        now ++;
    }
}
