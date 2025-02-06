#include <iostream>

using namespace std;

int main()
{
    int first_main[4];
    int first_guest[4];
    int second_main[4];
    int second_guest[4];
    cin >> first_main[0] >> first_main[1] >> first_main[2] >> first_main[3] >> first_guest[0] >> first_guest[1] >> first_guest[2] >> first_guest[3] >> second_main[0] >> second_main[1] >> second_main[2] >> second_main[3] >> second_guest[0] >> second_guest[1] >> second_guest[2] >> second_guest[3];
    cout << first_main[0]+first_main[1]+first_main[2]+first_main[3] << ":" << first_guest[0]+first_guest[1]+first_guest[2]+first_guest[3] << "\n" << second_main[0]+second_main[1]+second_main[2]+second_main[3] << ":" << second_guest[0]+second_guest[1]+second_guest[2]+second_guest[3] << "\n";
    if(first_main[0]+first_main[1]+first_main[2]+first_main[3] > first_guest[0]+first_guest[1]+first_guest[2]+first_guest[3] && second_main[0]+second_main[1]+second_main[2]+second_main[3] > second_guest[0]+second_guest[1]+second_guest[2]+second_guest[3])
    {
        cout << "Win";
        return 0;
    }
    else if(first_main[0]+first_main[1]+first_main[2]+first_main[3] < first_guest[0]+first_guest[1]+first_guest[2]+first_guest[3] && second_main[0]+second_main[1]+second_main[2]+second_main[3] < second_guest[0]+second_guest[1]+second_guest[2]+second_guest[3])
    {
        cout << "Lose";
        return 0;
    }
    else
    {
        cout << "Tie";
        return 0;
    }
}
