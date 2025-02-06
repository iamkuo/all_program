#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int n_copy;
    vector<int> breaked(0);
    while(cin >> n)
    {
        n_copy = n;
        while(n_copy != 0)
        {
           breaked.push_back(n_copy%10);
           n_copy/=10;
        }
        for(int i=0;i<breaked.size();i++)
        {

        }
    }
}
