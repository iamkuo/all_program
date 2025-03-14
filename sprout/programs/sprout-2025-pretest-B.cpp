using namespace std;
#include <iostream>
#include <vector>

int main()
{
    long long int n,m,k,a,a_prev=0;
    vector<long long int> ans;
    cin >> n >> m >> k;
    if(n<k)
    {
    	cout << -1;
    	return 0;
    } 
    int serial = 1;//在第幾題
    for(int i=0;i<n;i++)//在第幾個答案
    {
    	//cout << "i" << i << endl;
        cin >> a;
        if(a <= a_prev)
        {      
            //cout << k-serial << " " << n-i << endl;
            serial ++;
        }
        ans.push_back(serial);
    	if (k-serial < n-1-i) a_prev = a;
    	else a_prev = m+1;

    }
    if(serial > k)
	{
    	//cout << "nope" << endl;
        cout << -1;
    } else
    //ans.push_back(n+1);
    //for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    //cout << endl;
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    return 0;
}
