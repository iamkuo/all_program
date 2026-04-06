#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> p_sum(n+1,0);//1-index
    for(int i=0;i<n;i++)
    {
        cin >> p_sum[i+1];
        p_sum[i+1] += p_sum[i];
    }
    //for(int i : p_sum) cout << i << " ";
    //cout << "\n";
    int l,r,mid;
    double goal,left_if,right_if,a,b,ss_sum,start_sum;
    for(int i=0;i<m;i++)
    {
        cin >> l >> r >> a >> b;
        start_sum = p_sum[l-1];
        ss_sum = p_sum[r]-p_sum[l-1];
        goal = a/(a+b);
        //cout << "goal : " << goal << "\n";
        //cout << "ss_sum : " << ss_sum << "\n";
        while(l<=r) //l<=ans<=r
        {
            mid = (l+r)/2;
            left_if = p_sum[mid-1]-start_sum;
            right_if = p_sum[mid]-start_sum;
            //cout << "left if : " << left_if << "\n";
            //cout << "right if : " << right_if << "\n";
            left_if /= ss_sum;
            right_if /= ss_sum;
            if(left_if < goal && right_if >= goal)
            {
                cout << mid << "\n";
                break;
            }
            if(left_if >= goal) // too right
            {
                //cout << mid << " too right\n";
                r = mid-1;
            }
            else // too left
            {
                //cout << mid << " too left\n";
                l = mid+1;
            }
        }
    }
    return 0;
}
