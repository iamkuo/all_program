#include <iostream>

using namespace std;

int main()
{
    int min_guess = 1;
    int max_guess = 1000;
    string ans;
    while(ans != "correct")
    {
        cout.flush();
        cout << min_guess+(max_guess-min_guess)/2 << endl;
        cin >> ans;
        if(ans == "correct")
        {
            break;
        }
        if(ans == "lower")
        {
            if((max_guess-min_guess)/2 == 0)
            {
                max_guess = max_guess - 1;
            }
            else
            {
                max_guess = min_guess+(max_guess-min_guess)/2-1;
            }
        }
        else if(ans == "higher")
        {
            if((max_guess-min_guess)/2 <= 1)
            {
                min_guess = min_guess+(max_guess-min_guess)/2+1;
            }
            else
            {
                min_guess = min_guess+(max_guess-min_guess)/2+1;
            }
        }
    }
}

