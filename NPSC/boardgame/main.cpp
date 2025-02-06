#include <iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str="\n";
    getline(cin,str);
    string dat[n];
    int ci[n];
    int ci_add[n];
    int ci_multiply[n];
    int add_now,multiply_now = 0;
    string dat_add[n];
    string dat_multiply[n];
    for(int i=0;i<n;i++)
    {
        getline(cin,dat[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout << dat[i] << endl;
    }
    for(int i=0;i<n;i++)
    {

    }
    /*
    for(int i=0;i<n;i++)
    {
        if(dat[i][0] == '+')
        {
            ci_add[add_now] = ci[i];
            dat_add[add_now] = dat[i];
            add_now ++;
        }
        else
        {
            ci_multiply[multiply_now] = ci[i];
            dat_multiply[multiply_now] = dat[i];
            multiply_now ++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i<add_now)
        {
            dat[i] = dat_add[i];
            ci[i] = ci_add[i];
        }
        else
        {
            dat[i] = dat_multiply[i-add_now];
            ci[i] = ci_multiply[i-add_now];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << dat[i] << endl;
        cout << ci[i] << endl;
    }
    */





}
