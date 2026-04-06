#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;//ppl count
    int m;//at index m explode
    int k;//explode time
    int start = 0;
    cin >> n >> m >> k;
    vector<int> numbers;
    for (int i = 1;i<=n;i++)
    {
        numbers.push_back(i);
    }
    for (int i = 0;i<k;i++)
    {
        start = (start+(m-1))%numbers.size();
        numbers.erase(numbers.begin()+start);
    }
    cout << numbers[start%numbers.size()] << endl;
    return 0;
}
