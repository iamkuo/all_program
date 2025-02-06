using namespace std;

#include <bits/stdc++.h>


int main()
{
    int w,h,n;
    int find_many = 0;
    cin >> w >> h >> n;
    int ws[26];
    int hs[26];
    for(int i=0;i<26;i++)
    {
        ws[i] = -1;
        hs[i] = -1;
    }
    char orienteer_map[w][h];
    for (int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            cin >> orienteer_map[i][j];
        }
    }
    for(int j=0;j<w;j++)
    {
        for(int k=0;k<h;k++)
        {
            if(orienteer_map[j][k]-'a' >= 0)
            {
                find_many ++;
                ws[orienteer_map[j][k]-'a'] = j;
                hs[orienteer_map[j][k]-'a'] = k;
            }
        }
    }
    if(find_many < n)
    {
        cout << "Mission fail." << endl;
        return 0;
    }
    int outputed = 0;
    for(int i=0;i<26;i++)
    {
        if(ws[i] != -1)
        {
            outputed ++;
            cout << ws[i] << " " << hs[i] << "\n";
            if(outputed == n)
            {
                return 0;
            }
        }
    }


}
