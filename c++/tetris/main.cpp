#include <iostream>

using namespace std;

class tetris
{
public:
    int x;
    int y;
};

int main()
{
    int x,y;
    cin >> x >> y;

    int n;
    cin >> n;
    int command;
    int direction = 1;
    // down 1 left 2 up 3 right 4
    int screen[x+1][y+1];
    for(int i=0;i<x+1;i++)
    {
        for(int j=0;j<y+1;j++)
        {
            screen[i][j] = 0;
        }
    }
    tetris center;
    if(x%2 == 1)
    {
        center.x = x/2+1;
    }
    else
    {
        center.x = x/2;
    }
    center.y = 1;
    for(int i=0;i<n;i++)
    {
        cin >> command;
        center.y ++;
        if(command == 1)
        {
            if(direction == 2)
            {
                if(center.x < x)
                {
                    center.x += 1;
                }
            }
            else
            {
                if(center.x < x-1)
                {
                    center.x += 1;
                }
            }
        }
        else if(command == 2)
        {
            if(direction == 4)
            {
                if(center.x > 1)
                {
                    center.x -= 1;
                }
            }
            else
            {
                if(center.x > 2)
                {
                    center.x -= 1;
                }
            }
        }
        else if(command == 3)
        {
            if(direction == 3)
            {
                center.y = y;
            }
            else
            {
                center.y = y-1;
            }
        }
        else if(command == 4)
        {
            if(center.x != 1 && center.x != x && center.y != y)
            {
                direction ++;
                if(direction == 5)
                {
                    direction = 1;
                }
            }
        }
        //cout << endl << center.x << " " << center.y << " " << direction << endl;
        if(direction == 3)
        {
            if(center.y == y)
            {
                break;
            }
        }
        else
        {
            if(center.y == y-1)
            {
                break;
            }
        }
    }
    if(direction == 1)
    {
        screen[center.x][center.y] = 1;
        screen[center.x-1][center.y] = 1;
        screen[center.x+1][center.y] = 1;
        screen[center.x][center.y+1] = 1;
    }
    else if(direction == 2)
    {
        screen[center.x][center.y] = 1;
        screen[center.x][center.y-1] = 1;
        screen[center.x][center.y+1] = 1;
        screen[center.x-1][center.y] = 1;
    }
    else if(direction == 3)
    {
        screen[center.x][center.y] = 1;
        screen[center.x-1][center.y] = 1;
        screen[center.x+1][center.y] = 1;
        screen[center.x][center.y-1] = 1;
    }
    else if(direction == 4)
    {
        screen[center.x][center.y] = 1;
        screen[center.x][center.y-1] = 1;
        screen[center.x][center.y+1] = 1;
        screen[center.x+1][center.y] = 1;
    }
    for(int i=1;i<=y;i++)
    {
        for(int j=1;j<=x;j++)
        {
            cout << screen[j][i];
        }
        cout << "\n";
    }
}
