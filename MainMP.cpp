#include<iostream>

using namespace std;

int check(char gameBoard1[2][2]){

//Variable to store the winner. Player A is value 1 // Player B is value 2
int winner=0;
//bool inlineXA,inlineYA,diagNormalA,diagOpA,inlineXB,inlineYB,diagNormalB,diagOpB=0;(pourqoui ça marche pas ça?)
int i,j=0;
bool inlineXA=false;
bool inlineYA=0;
bool diagNormalA=0;
bool diagOpA=0;
bool inlineXB=0;
bool inlineYB=0;
bool diagNormalB=0;
bool diagOpB=false;

//CHECK FOR PLAYER A

//check line in X and Y
for (i=0;i<3;i++){
        if(gameBoard1[i][j]=='X' && gameBoard1[i][j+1]=='X' && gameBoard1[i][j+2]=='X')inlineXA=1;
        for ( j=0;j<3;j++){
        if(gameBoard1[i][j]=='X' && gameBoard1[i+1][j]=='X' && gameBoard1[i+2][j]=='X')inlineYA=1;
                          }
                 }

//check diagonals
if((gameBoard1[0][0]=='X')&&(gameBoard1[1][1]=='X')&&(gameBoard1[2][2]=='X'))diagNormalA=1;
if((gameBoard1[0][2]=='X')&&(gameBoard1[1][1]=='X')&&(gameBoard1[2][0]=='X'))diagOpA=1;

//CHECK FOR PLAYER B

//check line in X and Y
for (i=0;i<3;i++){
        if(gameBoard1[i][j]=='O' && gameBoard1[i][j+1]=='O' && gameBoard1[i][j+2]=='O')inlineXB=1;
        for ( j=0;j<3;j++){
        if(gameBoard1[i][j]=='O' && gameBoard1[i+1][j]=='O' && gameBoard1[i+2][j]=='O')inlineYB=1;
                          }
                 }

//check diagonals
if((gameBoard1[0][0]=='O')&&(gameBoard1[1][1]=='O')&&(gameBoard1[2][2]=='O'))diagNormalB=1;
if((gameBoard1[0][2]=='O')&&(gameBoard1[1][1]=='O')&&(gameBoard1[2][0]=='O'))diagOpB=1;

//set winner(if anny)||diagOpA==true
if(inlineXA==true||inlineYA==true||diagNormalA==true||diagOpA)winner=1;
else if(inlineXB==true||inlineYB==true||diagNormalB==true||diagOpB==true)winner=2;
else winner=0;

return winner;

}

int main(){

cout<<"-------------------Morpion Deluxe Console Edition TRT ---------------------\n\n";

cout<<"This is a classical tic-tac-toe 3x3 game\nEach player chooses his case and sign(either X or O) and inputs it.\nFirst, player chooses sign and then where to place it(exemple: 1,1)\nAt the end, the player doing the first inline 3 X or 3 O wins\n\n\n";

char gameBoard[2][2];
char playerAsign, playerBsign;
int numberOfTurns=5;
int row,column=0;
int i,j=0;
int checkVal=0;

//player interaction and data input (to test int from string (position))
while(numberOfTurns>0){
//input player A
cout<<"Player A ! Your turn. Sign : ";
cin>>playerAsign;
cout<<" Row : ";
cin>>row;
cout<<" Column : ";
cin>>column;
gameBoard[row][column]=playerAsign;

//input player B
if(numberOfTurns>1){
    cout<<"Player B ! Your turn. Sign : ";
    cin>>playerBsign;
    cout<<" Row : ";
    cin>>row;
    cout<<" Column : ";
    cin>>column;
    gameBoard[row][column]=playerBsign;
                    }
//decrease turns left
numberOfTurns--;


//test for inline
checkVal=check(gameBoard);
if(checkVal==1){cout<<"\nPlayer A wins !!!!Congratulations";break;}
else if(checkVal==2){cout<<"\nPlayer B wins !!!!Congratulations";break;}

}

return 0;
}
