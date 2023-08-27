#include <iostream>
#include <vector>
using namespace std;

vector < vector <char> > boardOG {
        
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}

    };
vector < vector <char> > boardEmpty {
        
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}

    };
    
    
int turn = 1;
int row, col;

void boardStat() {
        cout<<"BOARD: \n\n";
    for (int i=0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout<<boardOG.at(i).at(j)<< " ";
        }
        cout<<endl;
    }
    }
    int checkWin () {
        char arr[3];
        int ret = 0;
        
        //checking each row for horizontal win
        int countX = 0, countO = 0;
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 3; y++){
                //STORING elements of each row in an array
                arr[y] = boardOG.at(x).at(y);
            }
            
            //CHECKING ARRAY FOR ALL X OR O
            countX = countO = 0;
            for (int z = 0; z < 3; z++){
                    
                    if (arr[z] == 'X'){
                        countX++;
                    }
                    else if (arr[z] == 'O'){
                        countO++;
                    }
            }
                    if (countX == 3){
                        ret = 1;
                    }
                    else if (countO == 3){
                        ret = 2;
                    }
                    
                }
                
                //checking each row for vertical win
                for (int a = 0; a < 3; a++){
                    for (int b = 0; b < 3; b++){
                        //STORING ELEMENTS OF EACH COLUMN IN AN ARRAY
                        arr[b] = boardOG.at(b).at(a); 
                    }
                    
                    //COUNTING X's AND O's
                    countX = countO = 0;
                    for (int z = 0; z < 3; z++){
                    
                    if (arr[z] == 'X'){
                        countX++;
                    }
                    else if (arr[z] == 'O'){
                        countO++;
                    }
            }
                    if (countX == 3){
                        ret = 3;
                    }
                    else if (countO == 3){
                        ret = 4;
                    }
                    
                    
                }
                
            //CHECKING FOR L-R DIAGONAL WIN
            countX = 0, countO = 0;
            for (int c = 0; c < 3; c++){
                    //STORING diagonal elements in an array
                    if ( boardOG.at(c).at(c) == 'X' ){
                        countX++;
                    }
                    else if (boardOG.at(c).at(c) == 'O'){
                        countO++;
                    }
                    
                }
            
            if (countX == 3){
                ret = 5;
            }
            else if (countO == 3){
                ret = 6;
            }
            
            //CHECKING FOR (R-L) DIAGONAL WIN
            countX = 0, countO = 0;
            for (int d = 0; d < 3; d++){
                if ( boardOG.at(2 - d).at(d) == 'X'){
                    countX++;
                }
                else if (boardOG.at(2 - d).at(d) == 'O'){
                    countO++;
            }
            if (countX == 3){
                ret = 7;
            }
            else if (countO == 3){
                ret = 8;
            }
            
        }
        if ((countX != 3) && (countO != 3))
            return ret;
        else {
            return 0;
        }
    }

    
        void printWin( int n){
           string winWay;
            if (n >= 7){
                winWay = "diagonally (R-L)";
            }
            else if (n >= 5){
                winWay = "diagonally (L-R)";
            }
            else if (n >= 3){
                winWay = "vertically";
            }
            else if (n >= 1){
                winWay = "horizontally";
            }
    
            
            if (n == 0){
                cout<<" ";
            }
            else if (n % 2 != 0){
            n = 1;
            boardStat();
            cout << "PLAYER "<<n<<" wins "<<winWay;
            
            }
            else if (n % 2 == 0){
                n = 2;
                boardStat();
                cout << "PLAYER "<<n<<" wins "<<winWay;
                
            }
            
        

    }
        
    
int movePrompt () {
            cout<<"\nEnter Your Move ";
            if (turn % 2 != 0){
            cout<<"Player 1: ";
            cin>>row>>col;
            if ( (boardOG.at(row-1).at(col-1) == 'X') || (boardOG.at(row-1).at(col-1) == 'O') ){
                cout<<"INVALID MOVE\n";
                return 0;
            }
            else {
            boardOG.at(row-1).at(col-1) = 'X';
            return 1;
            }
            }
            else {
                cout<<"Player 2: ";
                cin>>row>>col;
                 if ( (boardOG.at(row-1).at(col-1) == 'X') || (boardOG.at(row-1).at(col-1) == 'O') ){
                cout<<"INVALID MOVE\n";
                return 0;
            }
            else {
            
            boardOG.at(row-1).at(col-1) = 'O';
            return 1;
            }

        }
    }
    
    
int main() {
    // Write C++ code here
    cout<<"PLAYER 1 PLAYS X AND PLAYER 2 PLAYS O\n\n";
    cout<<"TO ENTER YOUR MOVE - TYPE ROW NUMBER, SPACE, COLUMN NUMBER\n\n";
    char YesNo;
    do {
    boardOG = boardEmpty;
    turn = 1;
    boardStat();
    int winner = 0;
    while (turn <= 9){
    //CHECKING IF MOVE IS VALID
    int valid = movePrompt();
    if (valid == 0){
        turn = turn;
        
    }
    else if (valid == 1){
    turn++;
    }
    winner = checkWin();
    printWin (winner);
    if (winner != 0){
        break;
    }
    cout<<endl;
    boardStat();
    }
    if (winner == 0){
        cout<<"\nIT'S A DRAW\n\n";
       
    }
     cout<<"\n\nUP FOR ANOTHER GAME? (Y or N): ";
        cin>>YesNo;
    
    } while ( (YesNo == 'Y') || (YesNo == 'y') );
    
    return 0;
}
