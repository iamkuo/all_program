#include <bits/stdc++.h>

using namespace std;

bool number_sort(int a,int b)
{
    return a < b;
}

int main()
{
    int n;
    cin >> n;
    int s[n];
    int d[n];
    int cost = 0;
    vector<int> number(0);
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        cin >> d[i];
    }
    for(int i=0;i<n;i++)
    {
        if(d[i] > 100)
        {
            cost += (d[i]-100)*5;
            number.push_back(s[i]);
        }
    }
    sort(number.begin(),number.end(),number_sort);
    for(int i=0;i<number.size();i++)
    {
        cout << number[i] << " ";
    }
    cout << "\n";
    cout << cost;

}
