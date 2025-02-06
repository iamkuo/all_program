//question F
#include <iostream>
#include <vector>

using namespace std;

int transfer(int *data, int start, int stop){
    int i=0;
    while(start+i < stop-i){
        int temp = data[start+i];
        data[start+i] = data[stop-i];
        data[stop-i] = temp;
        i++;
    }
    return 0;
}

int caldif(int *data, int n){
    int counter=0;
    for(int i=0; i<n-1;i++){
        if (data[i+1]!=data[i]) counter++;
    }
    return counter;
}



int main()
{
    int n,k;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int source[n];
    for(int i=0; i<n;i++){
        cin >> source[i];
    }
    int start=1;
    int stop = n-1;
    int eff = 2;
    int chg = 0;

    start = 1;
    int havechange = 0;
    // change eff=2
    while(start < n){
        while(source[start] != source[start-1] && start < n) start++;
        stop = n-2;
        while((source[stop] != source[stop+1] || source[start] == source[stop]) && stop > start) stop--;
        if (start < stop){
            transfer(source, start, stop);
            chg++;
            havechange++;
            if (chg >= k) {
                for(int i=0; i<n;i++){
                    cout << source[i] << " ";
                }
                cout<<endl;
                cout << caldif(source, n) << endl;
                return 0;
            }
        }else{
            start++;
        }
    }
    //eff = 1, first and last change
    start = 0;
    havechange = 1;
    while(havechange == 1){
        havechange = 0;
        for(stop=n-2; stop >0;stop--){
            if (source[stop] == source[stop+1] && source[stop] != source[start]){
                transfer(source, start, stop);
                chg++;
                havechange++;
                if (chg >= k) {
                    for(int i=0; i<n;i++){
                        cout << source[i] << " ";
                    }
                    cout<<endl;
                    cout << caldif(source, n) << endl;
                    return 0;
                }
            }
        }
    }
    stop = n-1;
    havechange = 1;
    while(havechange == 1){
        havechange = 0;
        for(start=1; start < n-1;start++){
            if (source[start] == source[start-1] && source[stop] != source[start]){
                transfer(source, start, stop);
                chg++;
                havechange++;
                if (chg >= k) {
                    for(int i=0; i<n;i++){
                        cout << source[i] << " ";
                    }
                    cout<<endl;
                    cout << caldif(source, n) << endl;
                    return 0;
                }
            }
        }
    }
    for(int i=0; i<n;i++){
        cout << source[i] << " ";
    }
    cout<<endl;
    cout << caldif(source, n) << endl;
    return 0;
}
