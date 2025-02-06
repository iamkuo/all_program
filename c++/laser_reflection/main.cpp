#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class mirror
{
public:
    int x,y,t,key,xyrank,yxrank;
};

vector<mirror> mirrors;
int n;
int key_now = 0;
int direction = 1;
bool hit = false;
int mirror_number;

bool xysort(mirror a,mirror b)
{
    if(a.x < b.x)
    {
        return true;
    }
    else if(a.x == b.x)
    {
        return a.y < b.y;
    }

    return false;
}

bool yxsort(mirror a,mirror b)
{
    if(a.y < b.y)
    {
        return true;
    }
    else if(a.y == b.y)
    {
        return a.x < b.x;
    }

    return false;
}

bool key_sort(mirror a,mirror b)
{
    return a.key < b.key;
}

int main()
{
    int hits = 0;
    cin >> n;
    mirrors.resize(n+1);
    mirrors[0].x = 0;
    mirrors[0].y = 0;
    mirrors[0].t = NULL;
    mirrors[0].key = 0;
    for(int i=1;i<n+1;i++)
    {
        cin >> mirrors[i].x >> mirrors[i].y >> mirrors[i].t;
        mirrors[i].key = i;
    }
    sort(mirrors.begin(),mirrors.end(),xysort);
    vector<int> px(n+1);
    vector<int> py(n+1);
    for(int i=0;i<n+1;i++)
    {
        mirrors[i].xyrank = i;
        px[i] = mirrors[i].key;
    }
    sort(mirrors.begin(),mirrors.end(),yxsort);
    for(int i=0;i<n+1;i++)
    {
        mirrors[i].yxrank = i;
        py[i] = mirrors[i].key;
    }
    sort(mirrors.begin(),mirrors.end(),key_sort);
    int next = -1;
    while(true)
    {
        if(hits % 2 == 0)
        {
            next = mirrors[key_now].yxrank+direction;
            if(next < 0 || next > n)
            {
                cout << hits;
                return 0;
            }
            next = py[next];
            if(mirrors[key_now].y != mirrors[next].y)
            {
                cout << hits;
                return 0;
            }
        }
        else
        {
            next = mirrors[key_now].xyrank+direction;
            if(next < 0 || next > n)
            {
                cout << hits;
                return 0;
            }
            next = px[next];
            if(mirrors[key_now].x != mirrors[next].x)
            {
                cout << hits;
                return 0;
            }
        }
        if(next != 0)
        {
            hits ++;
            if(mirrors[next].t == 1)
            {
                direction *= -1;
            }
        }
        key_now = next;
    }
}
