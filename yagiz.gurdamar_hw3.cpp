#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int xx;
int yy;
int m = 3;

bool checkFormat(string move) {    
    int sub= move.find("-");
  string parse1= move.substr(0,1);
  string parse2= move.substr(2,3);
  int parser1= stoi(parse1);
  int parser2= stoi(parse2);
  if (sub<=0){
    return false;
  }
  else{
      if (parser1>3 || parser1<0){
          return false;
      }
      else if(parser2>3 || parser2<0){
         return false;  
        }
      else{
          return true;
      }
  } 
}
bool checkWinner(string tictactoeBoard[][3], const char* symbol) {
    string s;
    stringstream ss(symbol);
    //ss << symbol;
    ss >> s;
   
    if (xx == yy) {
        for (int i = 0; i < m; i++) {
            if (tictactoeBoard[i][i] != s)
                break;
            if (i == m - 1) {
                return true;
            }
        }
    }
  for (int i=0; i<3;i++){
    string winner = tictactoeBoard[i][0];
    if (tictactoeBoard[i][1] == winner && tictactoeBoard[i][2] == winner ){
      return true;
    }

}
  for (int i=0; i<3;i++){
    string winner=tictactoeBoard[0][i];
    if (tictactoeBoard[1][i]==winner && tictactoeBoard[2][i]==winner){
      return true;
    }
  }
    return false;
}
void print(string tictactoeBoard[][3]) {
    cout << "Current board: "<<endl;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (!tictactoeBoard[a][b].find_first_not_of("0,1,2,3,4,5,6,7,8,9")) {
              if (b<2){
                cout << " " + tictactoeBoard[a][b] + " ";
              }
              else if(b=2){
                cout << " " + tictactoeBoard[a][b] + "";                
              }
              else if (a<2){
                cout << " " + tictactoeBoard[a][b] + " ";
              }
              else if(a=2){
                cout << " " + tictactoeBoard[a][b] + "";                
              }
                      
            }
            else {
              if (b<2){
                cout << "   ";               
              }
              else {
                cout << "  ";                
              }              
            }
            if (b != 2)
                cout << "|";
        }
        cout << endl;
        if (a != 2)
            cout << "-----------"<<endl;
    }
}
bool playerMove(string p1, const char* s, string tictactoeBoard[][3]) {
    string move;
    bool is_it_Valid;

    cout << p1 + ", please enter your move: ";
    cin >> move;

    is_it_Valid = checkFormat(move);

    stringstream aa, aa2;
    aa << move[0];
    aa >> xx;

    aa2 << move[2];
    aa2 >> yy;

    if (is_it_Valid) {
        if (tictactoeBoard[xx - 1][yy - 1] != "X" && tictactoeBoard[xx - 1][yy - 1] != "O") {
            tictactoeBoard[xx - 1][yy - 1] = s;
            return true;
        }
        else {
            cout << "That location is already full!"<<endl;
            return false;
        }
    }
    else {
        cout << "Please enter correct move format!"<<endl;
    }
    return false;
}

void playGame(string p1, const char* s1, string p2, const char* s2, int *p1S, int *p2S) {
    
    string tictactoeBoard[3][3] = { {"1","2", "3"}, {"4","5","6"}, {"7", "8", "9"}};
    int count = 0;
    bool is_it_Winner = false;
  while (!is_it_Winner || count < 9) {
    
        print(tictactoeBoard);
        while (!playerMove(p1, s1, tictactoeBoard));
        count++;
        is_it_Winner = checkWinner(tictactoeBoard, s1);
        if (is_it_Winner) {
            *p1S += 1;
            return;
        }
      else if(count == 9){return;}
        print(tictactoeBoard);
        while (!playerMove(p2, s2, tictactoeBoard));
        is_it_Winner = checkWinner(tictactoeBoard, s2);
        count++;
        if (is_it_Winner) {
            *p2S += 1;
            return;
        }
      else if(count == 9){return;}
    }
}

int main()
{
    string p_1_N, p_2_N;
    int p_1_S = 0, p_2_S = 0;
    cout << "Welcome to Tic-Tac-Toe!"<<endl;
    cout << "Player 1, please enter your name: ";
    cin >> p_1_N;
    cout << "Hello, " + p_1_N +". You are going to play with X\n";
    
    cout << "Player 2, please enter your name: ";
    cin >> p_2_N;
    cout << "Hello, " + p_2_N + ". You are going to play with O\n";
    cout<< ""<<endl;
    cout << "Starting a new game..."<<endl;

    // player1 with symbol "X" starts the game
    playGame(p_1_N, "X", p_2_N, "O", &p_1_S, &p_2_S);
    if (p_1_S == 1) cout << p_1_N + " is the winner! Current Scores: \n ";
    else if (p_2_S == 1) cout << p_2_N + " is the winner! Current Scores: \n ";
    else cout << "The game ended in a draw!"<<endl;

    cout << "Current Scores: \n";

    cout << p_1_N + ": " + to_string(p_1_S) +  "   " + p_2_N + ": " + to_string(p_2_S) + "\n";
     cout<< ""<<endl;
    // player2 with symbol "O" starts the game playGame(p2Name, "O", p1Name, "X", p2Score, p1Score);
    cout << "Starting a new game..."<<endl;
    playGame(p_2_N, "O", p_1_N, "X", &p_2_S, &p_1_S);
    if(p_1_S>p_2_S){
      if (p_1_S == 2){  cout << p_1_N + " is the winner!\n";
      }
    else if (p_1_S == 1){  cout << p_1_N + " is the winner!\n";
      }
    }
      else if(p_1_S<p_2_S){
     if (p_2_S == 2) {cout << p_2_N + " is the winner!\n";
      }
    else if (p_2_S == 1) {cout << p_2_N + " is the winner!\n";
      }

      
      }
      
    else {
      cout << "The game ended in a draw!\n";  
      }
  
    cout << "Current Scores: "<<endl;
    cout << p_1_N + ": " + to_string(p_1_S) << + "   " + p_2_N + ": "  + to_string(p_2_S) +"\n";
  cout<< ""<<endl;

    cout << "Final Scores: "<<endl;
    cout << p_1_N + ": " + to_string( p_1_S) + "   " + p_2_N + ": " + to_string(p_2_S) + "\n";

    if (p_1_S >p_2_S) cout << p_1_N + " is the overall winner!\n";
    else if (p_2_S >p_1_S) cout << p_2_N + " is the overall winner!\n";
    else cout << "The overall game ended in a draw!"<<endl;
}