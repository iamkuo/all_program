#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n;
    int backward;
    cin >> m >> n;
    string password[m];
    string passcode;
    string tmp = "";
    for(int i=0;i<m;i++)
    {
        cin >> password[i];
    }
    cin >> passcode;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(password[i][j] == '0')
            {
                tmp = passcode.at(j) + tmp;
            }
            else
            {
                tmp = tmp + passcode.at(j);
            }
            //cout << tmp << "\n";
        }
        backward = 0;
        for(int j=0;j<n;j++)
        {
            if(password[i][j] == '1')
            {
                backward ++;
            }
        }
        if(backward % 2 == 1)
        {
            if(n%2 == 1)
            {
                passcode = tmp.substr(n/2+1,n/2)+tmp.substr(n/2,1)+tmp.substr(0,n/2);
            }
            else
            {
                passcode = tmp.substr(n/2,n/2) + tmp.substr(0,n/2);
            }
        }
        else
        {
            passcode = tmp;
        }
        tmp = "";
        cout << passcode << "\n";
    }

}
