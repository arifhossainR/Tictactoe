#include<bits/stdc++.h>
#include<windows.h>
#include "MMSystem.h"
using namespace std;

// custom header file for function
#include "function.h"


int main()
{
    // declaration part
    string player[2];
    char ar[3][3];
    char symbol[2];
    int position;
    bool draw=false;

    cout<<endl<<endl;
    cout<<"\t\t\t\t-- TicTacToe Game --"<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\tPresented By\n\n\t\t\t\t\tArif Hossain\n\t\t\t\t\t19CSE012\n\t\t\t\t\tDept of CSE, BSMRSTU"<<endl<<endl;


    // first player name
    cout<<"Enter first player name: ";
    getline(cin, player[0]);
    PlaySound("Notification.wav", NULL, SND_SYNC);

    // second player name
    cout<<"Enter second player name: ";
    getline(cin, player[1]);
    PlaySound("notification_2.wav", NULL, SND_SYNC);
    cout<<endl;

    // first player's game symbol
    cout<<player[0]<<"'s game symbol: ";
    cin>>symbol[0];
    PlaySound("Notification.wav", NULL, SND_SYNC);


    // second player's game symbol
    cout<<player[1]<<"'s game symbol: ";
    cin>>symbol[1];
    PlaySound("notification_2.wav", NULL, SND_SYNC);
    cout<<"\n"<<endl;


    // initialization
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            ar[i][j] = ' ';
        }
    }


    // initial game blank position
    cout<<"Initial blank game position\n"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<"  "<<ar[i][j];
            if(j<=1)
            {
                cout<<"  |";
            }
        }
        if(i<=1)
        {
            cout<<endl<<"  __    __    __  "<<endl;
        }
    }
    cout<<"\n"<<endl;


    // A loop to take input data from user
    cout<<"\n\t\t\t   N.B: Position will be must 1-9\n"<<endl<<endl;


    // Executing started from here
    for(int i=1; i<=8; i++)
    {
        if(i%2==1)
        {
            cout<<player[0]<<"'s turn:  ";
            cout<<"choose position: ";
            cin>>position;
            arrayFill(position, ar, symbol[0]);
            print(ar);
            PlaySound("Notification.wav", NULL, SND_SYNC);
            if(check(ar, symbol[0])==symbol[0])
            {
                cout<<player[0]<<" is Winner!!!"<<endl;
                PlaySound("winner_winner.wav", NULL, SND_SYNC);
                draw = true;
                break;
            }
        }
        else
        {
            cout<<player[1]<<"'s turn:  ";
            cout<<"choose position: ";
            cin>>position;
            arrayFill(position, ar, symbol[1]);
            print(ar);
            PlaySound("notification_2.wav", NULL, SND_SYNC);
            if(check(ar, symbol[1])==symbol[1])
            {
                cout<<player[1]<<" is Winner!!!"<<endl;
                PlaySound("winner_winner.wav", NULL, SND_SYNC);
                draw = true;
                break;
            }
        }
    }

    cout<<endl;
    if(draw==false)
    {
        cout<<"Match is draw!!!"<<endl;
        PlaySound("match_draw.wav", NULL, SND_SYNC);
    }
    cout<<endl<<endl;

    return 0;
}
