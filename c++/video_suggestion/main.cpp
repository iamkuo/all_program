#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class video
{
public:
    string s;
    int p;
    int l;
    int w;
    int r;
    float suggestion;
};

int movie_sort(video a,video b)
{
    return a.suggestion > b.suggestion;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    video dat[n];
    for (int i=0;i<n;i++)
    {
        cin >> dat[i].s;
        cin >> dat[i].p;
        cin >> dat[i].l;
        cin >> dat[i].w;
        cin >> dat[i].r;
    }
    for (int i=0;i<n;i++) dat[i].suggestion = 1.0*dat[i].p*dat[i].w/dat[i].l*dat[i].r;
    sort(dat,dat+n,movie_sort);
    for (int i=0;i<n;i++) cout << dat[i].s << endl;
    return 0;
}
