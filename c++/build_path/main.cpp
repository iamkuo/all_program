#include<bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a<b;
}

int findPath(int n, vector<vector<int> > data, int minHeight){
    vector<int> tmp(n, 1000000);
    vector<vector<int> > minpath(n, tmp);
    vector<int> v(2,0);
    //cout<<v[0]<<','<<v[1]<<endl;
    vector<vector<int> > pos(1, v);
    int dd[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
    minpath[0][0] = 0;
    while (!pos.empty()){
        int last = 0;
        int cr = pos[last][0];
        int cc = pos[last][1];
        pos.erase(pos.begin());
        //cout <<cr<<','<<cc<<'-'<<data[cr][cc]<<':';
        for(int i=0;i<4;i++){
            int nr = cr+dd[i][0];
            int nc = cc+dd[i][1];
            if (nr>=0 && nr<n && nc >=0 && nc < n && abs(data[nr][nc]-data[cr][cc]) <= minHeight){
                int mm = minpath[cr][cc]+1;
                if (mm < minpath[nr][nc] && mm < minpath[n-1][n-1]){
                    minpath[nr][nc] = mm;
                    if (nr != n-1 || nc != n-1){
                        v[0] = nr;
                        v[1] = nc;
                        pos.push_back(v);
                    }
                    else
                    {
                        return minpath[n-1][n-1];
                    }
                    //cout << nr<<','<<nc<<':'<<minpath[nr][nc]<<';';
                }
            }
        }
        //for(int i=0;i<pos.size();i++) cout <<'('<<pos[i][0]<<','<<pos[i][1]<<')';
        //cout<<endl;
    }
    if (minpath[n-1][n-1] >= 1000000) return -1;
    return minpath[n-1][n-1];

}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> col(n);
    vector<vector<int> > data(n, col);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> data[i][j];
    }
    //int minHeight = findHeight(n, data);
    //find out all deltaH
    vector<int> tdh;
    for(int i=0; i<n;i++){
        for(int j=0;j<n-1;j++){
            int tmp = abs(data[i][j+1]-data[i][j]);
            //if (tmp<0) tmp *= -1;
            tdh.push_back(tmp);
            tmp = abs(data[j+1][i]-data[j][i]);
            tdh.push_back(tmp);
        }
    }
    sort(tdh.begin(), tdh.end(), comp);
    vector<int> deltah;
    int tmp = tdh[0];
    deltah.push_back(tmp);
    for(int i=1;i<tdh.size();i++){
        if (tdh[i] != tmp){
            tmp = tdh[i];
            deltah.push_back(tmp);
        }
    }
    //for(int i=0;i<deltah.size(); i++) cout<< deltah[i]<<" ";
    //cout<<endl;
    //
    int L=0, R=deltah.size()-1;
    int pathR;
    while (R-L > 1){
        int idx = (L+R)/2;
        int minHeight = deltah[idx];
        int kk = findPath(n, data, minHeight);
        //cout <<L<<' '<<R<< " kk " <<kk<<endl;
        if ( kk >= 0){
            pathR = kk;
            R = idx;
        }else{
            L = idx;
        }
    }
    cout << deltah[R]<<endl<<pathR<<endl;
    return 0;
}
