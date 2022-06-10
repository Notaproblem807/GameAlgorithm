#include <iostream>
#include <algorithm>
#include<typeinfo>

using namespace std;



char Firstplayer;
char Secondplayer;
int result;
int Draw{1};
int i,j;
int MinMax(char cboard[3][3],int depth,bool isMax,int& score);
void winner(char b[3][3],int &res);
void win(int& result);

void evaluate(char b[3][3],int &res){
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]==Firstplayer)
               res= 2;
            else if (b[row][0]==Secondplayer)
               res=-2;
        }
    }
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]==Firstplayer)
                res= 2;
            else if (b[0][col]==Secondplayer)
                res=-2;
        }
    }
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==Firstplayer)
            res= 2;
        else if (b[0][0]==Secondplayer)
            res=-2;
    }
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==Firstplayer)
            res= 2;
        else if (b[0][2]==Firstplayer)
            res= -2;
    }
}

void draw(char tic[3][3],int &ree){
    int count=0;
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            cout<<tic[a][b]<<"";
            if(tic[a][b]==Firstplayer || tic[a][b]==Secondplayer){
                count=count+1;
            }
        }
        cout<<" "<<endl;
    }
    cout<<endl;
    if(count==9 && ree!=2 && ree!=-2){
        ree= Draw;
    }
}

void check(char tee[3][3],int & rev){
     int count=0;
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            if(tee[a][b]==Firstplayer || tee[a][b]==Secondplayer){
                count=count+1;
            }
        }
    }
    cout<<endl;
    if(count==9 && rev!=2 && rev!=-2){
        rev= Draw;
    }
}

void FindBestmove(char board[3][3],char &player,char &Ai,int &best,int &row,int& col){
    int bestval=-100;
    int y,s;
    for(y=0;y<3;y++){
        for(s=0;s<3;s++){
            if(board[y][s]=='-'){
                board[y][s]=Firstplayer;
                best=MinMax(board,0,false,best);
                //undo the move
                board[y][s]='-';
                if(best>bestval){
                row=y;
                col=s;
                bestval=best;
                }
            }
        }
    }
   
}

int MinMax(char cboard[3][3],int depth,bool isMax,int& score){
    evaluate(cboard,score);
    check(cboard,score);
    if(score==2){
        return score;
    }
    if(score==-2){
        return score;
    }

    if(score==1){
        return score;
    }

    if(isMax){
        int maxbest=-100;
        for(int o=0;o<3;o++){
            for(int x=0;x<3;x++){
                if(cboard[o][x]=='-'){
                    cboard[o][x]=Firstplayer;
                    maxbest=min(maxbest,MinMax(cboard,depth+1,!isMax,score));
                    cboard[o][x]='-';
                }
            }
        }
        return maxbest;
    }
    else{
        int minbest=100;
        for(int o=0;o<3;o++){
            for(int x=0;x<3;x++){
                if(cboard[o][x]=='-'){
                    cboard[o][x]=Secondplayer;
                    minbest=max(minbest,MinMax(cboard,depth+1,isMax,score));
                    cboard[o][x]='-';
                }
            }
        }
        return minbest;
    }

}


int main(){
    int Noplayer;
    cout<<"Tic Tac Toe Game"<<endl;
    cout<<"Single player game"<<endl;
    char Board[3][3];
    //fillup the board with'-' symbol
    for(int c=0;c<3;c++){
        for(int u=0;u<3;u++){
            Board[c][u]='-';
        }
    }
    cout<<"Enter the symbol first player"<<endl;
    cin>>Firstplayer;
    cout<<"Enter the symbol for AI player"<<endl;
    cin>>Secondplayer;

    int winneres;
    char ref;
    char turn='F';
    const type_info& type=typeid(i);
    const type_info&  typec=typeid(ref);
    const type_info& type2=typeid(j);
    while(winneres!=-2 || winneres!=1 ||winneres==2){
        switch (turn)
        {
        case 'F':
            cout<<"Enter the coordinate first player i and j "<<endl;
            cout<<"i:";
            cin>>i;
            
             
            if(i>2 || type==typec){
                cout<<"reenter the i value between 0-2"<<endl;
                cout<<"i";
                i=0;
                cin>>i;
            }
            cout<<"j:";
            cin>>j;
            if(j>2||type2==typec){
                cout<<"reenter the j value between 0-2"<<endl;
                cout<<"j";
                i=0;
                cin>>i;
            }
            if(Board[i][j]==Firstplayer||Board[i][j]==Secondplayer){
                cout<<"Enter another i and j space is occupied"<<endl;
                turn='F';
            }
            else{
                   Board[i][j]=Firstplayer;
            }
            cout<<"..........."<<endl;
            winner(Board,winneres);
            cout<<"winners"<<winneres<<endl;
            draw(Board,result);
            if(winneres==2 || winneres==1){
               win(result);
            }
            cout<<"............."<<endl;
            turn='S';
            break;
        case 'S':
            cout<<"Ai giving the i and j value "<<endl;
            FindBestmove(Board,Firstplayer,Secondplayer,result,i,j);
            cout<<"i:"<<i<<"j:"<<j<<endl;
            if(Board[i][j]==Firstplayer||Board[i][j]==Secondplayer){
                cout<<"Enter another i and j space is occupied"<<endl;
                turn='S';
            }
            else{
                  Board[i][j]=Secondplayer;
            }
            cout<<".........."<<endl;
            winner(Board,winneres);
            //evaluate(Board,result);
            draw(Board,result);
            cout<<".........."<<endl;
            if(winneres==-2 ||winneres==1){
                win(result);
            }
            turn='F';
            break;
        }
    }
}

void win(int &result){
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


void winner(char b[3][3],int &res){
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]==Firstplayer)
               res= 2;
            else if (b[row][0]==Secondplayer)
               res=-2;
        }
    }
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]==Firstplayer)
                res= 2;
            else if (b[0][col]==Secondplayer)
                res=-2;
        }
    }
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==Firstplayer)
            res= 2;
        else if (b[0][0]==Secondplayer)
            res=-2;
    }
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==Firstplayer)
            res= 2;
        else if (b[0][2]==Firstplayer)
            res= -2;
    }
}