#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string pass;
    int manyint=0;
    int manychar=0;
    int connectlen=0;
    bool hasint=false;
    bool onlyint=true;
    bool haschar=false;
    bool onlychar=true;
    int score = 0;
    cin >> pass;
    //score add
    //password basic need
    for (int i=0;i<pass.size();i++)
    {
        //ASCII 48 = 0
        //ASCII 57 = 9
        if (pass[i] >= '0' && pass[i] <= '9')
        {
            hasint = true;
            manyint ++;
        }
        //ASCII 65 = a
        //ASCII 90 = z
        if((pass[i] >= 'A' && pass[i] <= 'Z') || (pass[i] >= 'a' && pass[i] <= 'z'))
        {
            haschar = true;
            manychar ++;
        }
    }
    if(hasint && haschar && pass.size() > 8)
    {
        //cout << "score + 10 pass basic" << endl;
        score += 10;

    }
    else
    {
        //score minus
        //cout << "score - 5 not pass basic" << endl;
        score -= 5;
    }
    //len of password
    //cout << "score +" << pass.size()*3 << "len pass" << endl;
    score += pass.size()*3;
    //len of char
    //cout << "score +" << manychar*3 << "len char" << endl;
    score += manychar*3;
    //len of number
    //cout << "score +" << manyint*2 << "len int" << endl;
    score += manyint*2;
    //score minus
    //only char
    if (manyint == 0)
    {
        //cout << "score -" << pass.size() << "only char" << endl;
        score -= pass.size();
    }
    //only int
    if (manychar == 0)
    {
        //cout << "score -" << pass.size() << "only int" << endl;
        score -= pass.size();
    }
    //hard part
    for (int i=0;i<pass.size();i++)
    {
        if(pass[i] >= '0' && pass[i] <= '9')
        {
            connectlen+=1;
            //cout << connectlen << "connect len" << endl;
        }
        else
        {
            if (connectlen>1)
            {
                //cout << "score -" << (connectlen-1)*2 << "connect int" << endl;
                score -= (connectlen-1)*2;
            }
            connectlen = 0;
        }
    }
    if (connectlen>1)
    {
        //cout << "score -" << (connectlen-1)*2 << "connect int" << endl;
        score -= (connectlen-1)*2;
    }
    //output
    cout << score;


}
