#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
* global variables
*/

void print_winner(char player) {
  cout << "Spieler " << player << " hat das Spiel gewonnen!\n";
}

int get_number(char player) {
  int field;
  while (true) {
    cout << "Spieler " << player << ", bitte Spielfeld auswaehlen: ";
    cin >> field;
    if (field < 1 || field > 9) {
      field = 0;
      cout << "Bitte eine Zahl zwischen 1 und 9 eingeben!\n";
    }
    else {
      break;
    }
  }
  return field;
}

bool check_row(vector<string> &board) {
  for(auto row: board) {
    char temp_player = row[0];
    int match = 0;
    for(auto field: row) {
      if (field == temp_player) {
        match++;
      }
    }
    if (match == row.size()) {
      print_winner(temp_player);
      return true;
    }
  }
  return false;
}

bool check_col(vector<string> &board) {
  for(int col=0; col < board[0].size(); col++) {
    char temp_player = board[0][col];
    int match = 0;
    for(int row=0; row < board.size(); row++) {
      if (board[row][col] == temp_player) {
        match++;
      }
    }
    if (match == board[0].size()) {
      print_winner(temp_player);
      return true;
    }
  }
  return false;
}

bool game_over(int rounds, vector<string> &board) {
  //Hat ein Spieler gewonnen?
  //Checken den unterschiedlichen Kombination auf dem board
  if((board[0][0] == board[1][1] && board[2][2] == board[1][1]) ||
     ((board[0][2] == board[1][1] && board[2][0] == board[1][1]))
  ) {
    print_winner(board[1][1]);
    return true;
  }
  if (check_row(board) || check_col(board)) {
    return true;
  }

  //Anzahl der gespielten runden checken
  if(rounds <9) {
    return false;
  }
  else {
    cout << "Maximale Anzahl an Zuegen erreicht\n";
    return true;
  }
}

void print_board(vector<string> board) {
  cout << "\n----------\n";
  for (int i = 0; i < board.size(); i++) {
    cout << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n----------\n";
  }
}

void insert_move(vector<string> &board, char player) {
  /*
  * Hier sind noch einige Fehler eingebaut.
  * Idealerweise sollte man vor dem Eintragen ins Board noch ein paar Parameter checken.
  * z.B. darf es sich nur um eine Zahl zwischen 1-9 handeln,
  * was passiert wenn das Feld bereits belegt ist?
  * */
  while(true) {
    int field = get_number(player);
    // insert symbol
    field--;
    int row = field/3;
    int column = field%3;

    //check if field already used
    if (board[row][column] == 'X' || board[row][column] == 'O') {
      cout << "Feld ist bereits besetzt, bitte ein anderes wählen\n";
    }
    //insert move
    else {
      board[row][column] = player;
      break;
    }
  }
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

    rounds++;
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
    if(game_over(rounds, board)){
      break;
    }
  }

  return 0;
}