#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool game_over(int rounds /* board ?*/){
  //Hat ein Spieler gewonnen?
  //Checken den unterschiedlichen Kombination auf dem board

  //Anzahl der gespielten runden checken
  if(rounds <= 9) {
    return false;
  }
  else {
    return true;
  }
}

void print_board(vector<string> board) {
  for (int i = 0; i < board.size(); i++) {
    cout << board[i] << "\n"; //eventuell eine schönere Ausgabe des Boards
  }
}

void insert_move(/* hier fehlt was */) {
  /*
  * Hier sind noch einige Fehler eingebaut.
  * Idealerweise sollte man vor dem Eintragen ins Board noch ein paar Parameter checken.
  * z.B. darf es sich nur um eine Zahl zwischen 1-9 handeln,
  * was passiert wenn das Feld bereits belegt ist?
  * */
  int field;
  cout << "Spieler " << player << ", bitte Spielfeld auswaehlen: ";
  cin >> field;

  // insert symbol
  field--;
  int row = field/3;
  int column = field%3;

  //insert move
  board[row][column] = player;
}


int main() {
  // hier entsteht das Spiel TicTacToe
  std::cout << "Willkommen zu TicTacToe!\n";

  //Declare variables
  int rounds = 0;
  char player = 'X';

  // Declare Board
  vector<string> board = {
    "123",
    "456",
    "789"
  };

  // Print Board
  print_board(board);

  while (true) {

    insert_move(board, player);
    //switch player
    if(player == 'X') {
      player = 'O';
    }
    else {
      player = 'X';
    }

    print_board(board);

    /*
    * check end of game
    * Eine andere Möglichkeit wäre es in der while loop zu checken
    * anstatt nur true dort stehen zu haben.
    * */
    if(game_over(rounds)){
      break;
    }
  }

  return 0;
}