#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    long long int si;
    char c;
    cin >> n;
    cin >> m;
    cin >> c;
    for (int i=0;i<n;i++)
    {
        cin >> si;
        vector<int> binary_si;
        for (int j=0;j<m;j++)
        {
            binary_si.push_back(si%2);
            si /= 2;
        }
        for (int j=0;j<binary_si.size();j++)
        {
            if(binary_si[m-1-j] == 0) cout << ". ";
            else cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
