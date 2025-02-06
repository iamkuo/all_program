#include <iostream>

using namespace std;

int main()
{
    int many;
    int diff = 0;
    int max_len = 0;
    cin >> many;
    int cats[many];
    for(int i=0;i<many;i++)
    {
        cin >> cats[i];
    }
    for(int i=0;i<many-1;i++)
    {
        int counter = 2;
        if(cats[i] == cats[i+1])
        {
            diff = 0;
        }
        else
        {
            diff = 1;
        }
        for(int j=i+2;j<many;j++)
        {
            if (cats[i] == cats[j])
            {
                counter ++;
            }
            else
            {
                diff ++;
                if(diff == 2)
                {
                    break;
                }
                else
                {
                    counter ++;
                }
            }
        }
        if(counter > max_len)
        {
            max_len = counter;
        }
    }
    cout << max_len << endl;
}
