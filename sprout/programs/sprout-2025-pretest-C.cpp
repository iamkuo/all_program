#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,s1,s2,trash;
	int q;
	cin >> s >> q;
	int str_len = s.size();
	int sub_len;
	for(int i=0;i<q;i++)
	{
		cin >> s1 >> trash >> s2;
		sub_len = s1.size();
		for(int j=0;j<=str_len-sub_len;j++)
		{
			//cout << j << endl;
			if(s.substr(j,sub_len) == s1)
			{
				s.replace(j,sub_len,s2);
				str_len = s.size();
				break;
			}
		}
	}
	cout << s;
}