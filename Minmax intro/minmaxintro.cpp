#include <bits/stdc++.h>

using namespace std;

char Firstplayer;
char Secondplayer;
int Fwins{2};
int Swins{4};
int Draw{1};
int result;

void evaluate(char b[3][3],int &res){
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]==Firstplayer)
               res= 2;
            else if (b[row][0]==Secondplayer)
               res=4;
        }
    }
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]==Firstplayer)
                res= 2;
            else if (b[0][col]==Secondplayer)
                res=4;
        }
    }
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==Firstplayer)
            res= 2;
        else if (b[0][0]==Secondplayer)
            res=4;
    }
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==Firstplayer)
            res= 2;
        else if (b[0][2]==Firstplayer)
            res= 4;
    }
}

void draw(char tic[3][3],int &ree){
    int count=0;
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            cout<<tic[a][b]<<"_";
            if(tic[a][b]==Firstplayer || tic[a][b]==Secondplayer){
                count=count+1;
            }
        }
        cout<<""<<endl;
    }
    cout<<endl;
    if(count==9 && ree!=2 && ree!=4){
        ree= Draw;
    }
}


int main()
{
    int Noplayer;
    cout<<"Tic Tac Toe Game"<<endl;
    cout<<"Enter the player"<<endl;
    cin>>Noplayer;
    char Board[3][3];
    cout<<"Enter the symbol first player"<<endl;
    cin>>Firstplayer;
    cout<<"Enter the symbol second player"<<endl;
    cin>>Secondplayer;

    int i,j;
    char turn='F';
    while(result<1){
        switch (turn)
        {
        case 'F':
            cout<<"Enter the coordinate first player i and j "<<endl;
            cout<<"i:";
            cin>>i;
            cout<<"j:";
            cin>>j;
            if(Board[i][j]==Firstplayer||Board[i][j]==Secondplayer){
                cout<<"Enter another i and j space is occupied"<<endl;
                turn='F';
            }
            else{
                   Board[i][j]=Firstplayer;
            }
            cout<<"..........."<<endl;
            evaluate(Board,result);
            draw(Board,result);
            cout<<"............."<<endl;
            turn='S';
            break;
        case 'S':
            cout<<"Enter the coordinate second player i and j "<<endl;
            cout<<"i:";
            cin>>i;
            cout<<"j:";
            cin>>j;
            if(Board[i][j]==Firstplayer||Board[i][j]==Secondplayer){
                cout<<"Enter another i and j space is occupied"<<endl;
                turn='S';
            }
            else{
                  Board[i][j]=Secondplayer;
            }
            cout<<".........."<<endl;
            evaluate(Board,result);
            draw(Board,result);
            cout<<".........."<<endl;
            turn='F';
            break;
        }
    }
    switch (result)
    {
    case 2:
        cout<<"First Player Wins"<<endl;
        break;
    
    case 4:
        cout<<"Second Player Wins"<<endl;
        break;

    case 1:
        cout<<"Draw"<<endl;
        break;
    }
}