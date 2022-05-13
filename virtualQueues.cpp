#include <iostream>
using namespace std;
int space[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
int horplace;
bool tie;
int vertplace;
char token = 'X';





void functionstart(){

cout << "Use these numbers to determine where you want to put your X or O" << endl;

cout << "________________" << endl;
cout << "[" << space[0][0] << "]" << "[" << space[0][1] << "]" << "[" << space[0][2] << "]" << endl;
cout << "[" << space[1][0] << "]" << "[" << space[1][1] << "]" << "[" << space[1][2] << "]" << endl;
cout << "[" << space[2][0] << "]" << "[" << space[2][1] << "]" << "[" << space[2][2] << "]" << endl;
}
// this is creating the boxes for the board
void functionUI(){
    
int place;
    if('X' == token){
        cout << "Please Enter Space";
    }
    cin >> place;
    
    if('O' == token){
        cout << "Please Enter Space";
    }
    cin >> place;
 
    if(place==1){
        horplace=0;
        vertplace=0;
    }
    if(place==2){
        horplace=1;
        vertplace=0;
    }
    if(place==3){
        horplace=2;
        vertplace=0;
    }
    if(place==4){
        horplace=0;
        vertplace=1;
    }
    if(place==5){
        horplace=1;
        vertplace=1;
    }
    if(place==6){
        horplace=2;
        vertplace=1;
    }
    if(place==7){
        horplace=0;
        vertplace=2;
    }
    if(place==8){
        horplace=1;
        vertplace=2;
    }
    if(place==9){
        horplace=2;
        vertplace=2;
    }
    else{
    cout << "Please Enter Valid Place" << endl;
    }
    
    if(token == 'X' && space[horplace][vertplace] != 'X' && space [horplace][vertplace] != 'X'){
        space[horplace][vertplace]='X';
        token='O';
    }
    else if(token == 'O' && space[horplace][vertplace] != 'O' && space [horplace][vertplace] != 'O'){
        space[horplace][vertplace]='O';
        token='X';
    }
    else{
        cout << "No Free Spot" << endl;
        functionUI();
    }
    
    
    
}


bool functioncheck(){
    // this checks for wins, ties, losses, or if the game needs to continue
    for(int i=0; i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
            return true;
        }
        
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
        return true;
    }
   // I did have someone outside of my group help me set up this for loop inside of a for loop 
    for(int i=0;i<3;i++){
        for(int x=0;x<3;x++){
            if(space[i][x] != 'X' && space[i][x] != 'O'){
                return false;
            }
        }
    }
    
    tie=true;
    return false;
    
}


int main(){
    // this calls the functions and also shows the text on who is the winner
    while(!functioncheck()){
        functionstart();
        functionUI();
        functioncheck();
    }
    
    if(token == 'X' && tie == false){
        cout << "X WON!!!" << endl;
    }
        if(token == 'O' && tie == false){
        cout << "O WON!!!" << endl;
}
else{
    cout << "Draw" << endl;
}
}