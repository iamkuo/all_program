#include <iostream>

using namespace std;

int main()
{
    int number_count;
    cin >> number_count;
    int dif = number_count;
    int many[number_count];
    bool in_counted = false;
    int dat[number_count];
    for (int i=0;i<number_count;i++)
    {
        cin >> dat[i];
        many[i] = 0;
    }
    for (int i=0;i<number_count;i++)
    {
        if (many[i] == 0)
        {
            for (int j=i+1;j<number_count;j++)
            {
                if (dat[i] == dat[j])
                {
                    in_counted = true;
                    many[i] ++;
                    many[j] = -1;
                    dif --;

                }
            }
        }
    }
    cout << dif << endl;
    int maxrepeat = 0;
    for (int i=0;i<number_count;i++)
    {
        if (many[i] > maxrepeat)
        {
            maxrepeat = many[i];
        }
    }
    if (maxrepeat == 0)
    {
        cout << "NO";
    }
    else
    {
        for(int i=0;i<number_count;i++)
        {
            if (many[i] == maxrepeat)
            {
                cout << dat[i] << " ";
            }
        }
    }
    return 0;
}


