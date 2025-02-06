#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class student
{
public:
    string ID;
    string name;
    int order;
};

bool students_sort(student a,student b)
{
    if(a.ID[8] < b.ID[8])
    {
        return true;
    }
    else if(a.ID[8] == b.ID[8] && a.ID[0] < b.ID[0])
    {
        return true;
    }
    else if(a.ID[8] == b.ID[8] && a.ID[0] == b.ID[0])
    {
        return a.order<b.order;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<student> students(n);
    for(int i=0;i<n;i++)
    {
        cin >> students[i].ID >> students[i].name;
        students[i].order = i;
    }
    sort(students.begin(),students.end(),students_sort);
    for(int i=0;i<n;i++)
    {
        cout << students[i].ID[8] << ": " << students[i].name << "\n";
    }
    return 0;
}
