#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int length[3];
    cin >> length[0] >> length[1] >> length[2];
    sort(length, length+3);
    cout << length[0] << " " << length[1] << " " << length[2] << endl;
    if(length[2] > length[0]+length[1])
    {
        cout << "No";
        return 0;
    }
    else if(length[0]*length[0]+length[1]*length[1] < length[2]*length[2])
    {
        cout << "Obtuse";
        return 0;
    }
    else if(length[0]*length[0]+length[1]*length[1] == length[2]*length[2])
    {
        cout << "Right";
        return 0;
    }
    else if(length[0]*length[0]+length[1]*length[1] > length[2]*length[2])
    {
        cout << "Acute";
        return 0;
    }
}
