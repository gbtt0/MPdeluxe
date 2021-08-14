#include<iostream>

using namespace std;

int check(char gameBoard1[2][2]){

//Variable to store the winner. Player A is value 1 // Player B is value 2
int winner=0;
int i,j=0;
bool inlineXX=false;
bool inlineYX=0;
bool diagNormalX=0;
bool diagOpX=0;
bool inlineXO=0;
bool inlineYO=0;
bool diagNormalO=0;
bool diagOpO=false;

//CHECK FOR INLINE X

//check line in X and Y
for (i=0;i<3;i++){
        if(gameBoard1[i][j]=='X' && gameBoard1[i][j+1]=='X' && gameBoard1[i][j+2]=='X')inlineXX=1;
        for ( j=0;j<3;j++){
        if(gameBoard1[i][j]=='X' && gameBoard1[i+1][j]=='X' && gameBoard1[i+2][j]=='X')inlineYX=1;
                          }
                 }

//check diagonals
if((gameBoard1[0][0]=='X')&&(gameBoard1[1][1]=='X')&&(gameBoard1[2][2]=='X'))diagNormalX=1;
if((gameBoard1[0][2]=='X')&&(gameBoard1[1][1]=='X')&&(gameBoard1[2][0]=='X'))diagOpX=1;

//CHECK FOR INLINE O

//check line in X and Y
for (i=0;i<3;i++){
        if(gameBoard1[i][j]=='O' && gameBoard1[i][j+1]=='O' && gameBoard1[i][j+2]=='O')inlineXO=1;
        for ( j=0;j<3;j++){
        if(gameBoard1[i][j]=='O' && gameBoard1[i+1][j]=='O' && gameBoard1[i+2][j]=='O')inlineYO=1;
                          }
                 }

//check diagonals
if((gameBoard1[0][0]=='O')&&(gameBoard1[1][1]=='O')&&(gameBoard1[2][2]=='O'))diagNormalO=1;
if((gameBoard1[0][2]=='O')&&(gameBoard1[1][1]=='O')&&(gameBoard1[2][0]=='O'))diagOpO=1;

//set winner
if(inlineXX==true||inlineYX==true||diagNormalX=true||diagOpX)winner=1;
else if(inlineXO==true||inlineYO==true||diagNormalO==true||diagOpO==true)winner=2;
else winner=0;

return winner;

}

int main(){

cout<<"-------------------Morpion Deluxe Console Edition TRT ---------------------\n\n";

cout<<"This is a classical tic-tac-toe 3x3 game\nFirst, player chooses sign(X or O) and then where to place it(exemple: 1,1)\nThe player doing the first inline 3 X or 3 O wins\n\n\n";

char gameBoard[2][2];
char playerSign;
int numberOfTurns=5;
int row,column=0;
int i,j=0;
int checkVal=0;

//player interaction and data input (to test int from string (position))
while(numberOfTurns>0){
//input player A
cout<<"First player ! Your turn. Sign : ";
cin>>playerSign;
cout<<" Row : ";
cin>>row;
cout<<" Column : ";
cin>>column;
gameBoard[row][column]=playerSign;

//input player B
if(numberOfTurns>1){
    cout<<"Second player ! Your turn. Sign : ";
    cin>>playerSign;
    cout<<" Row : ";
    cin>>row;
    cout<<" Column : ";
    cin>>column;
    gameBoard[row][column]=playerSign;
                    }
//decrease turns left
numberOfTurns--;


//test for inline
checkVal=check(gameBoard);
if(checkVal==1){cout<<"\nPlayer with X wins !!!!Congratulations";break;}
else if(checkVal==2){cout<<"\nPlayer with O wins !!!!Congratulations";break;}

}

return 0;
}
