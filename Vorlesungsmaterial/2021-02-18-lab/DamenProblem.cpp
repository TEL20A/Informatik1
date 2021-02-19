#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool freie_spalte(int neu_reihe, int neue_spalte, vector<int> damen_spalten) {
   for(int reihe=0; reihe < neu_reihe; reihe++) {
      if (damen_spalten[reihe] == neue_spalte ||
          damen_spalten[reihe] + reihe == neu_reihe + neue_spalte ||
          damen_spalten[reihe] - reihe == neue_spalte - neu_reihe
         ) {
            return false;
         }
   }
   return true;
}

vector<vector<int>> platziere_dame(int neue_reihe, int max_spalten, vector<vector<int>> damen_lsg) {
   vector<vector<int>> neu_lsg;
   for(auto damen_spalten:damen_lsg) {
      // laufe durch alle spalten der Reihe
      for(int spalte=0; spalte < max_spalten; spalte++){
         if(freie_spalte(neue_reihe,spalte, damen_spalten)) {
            vector<int> temp = damen_spalten;
            temp.push_back(spalte);
            neu_lsg.push_back(temp);
         }
      }
   }
   return neu_lsg;
}

// durchlaufe Reihen
vector<vector<int>> damen_problen(int reihen, int spalten) {
   if(reihen == 0) {
      vector<vector<int>> damen = {{}};
      return damen;
   }
   else {
      return platziere_dame(reihen-1, spalten, damen_problen(reihen-1,spalten));
   }
}


void print_board(vector<vector<int>> &damen) {
   for(auto d:damen) {
      cout << "\nLoesung: \n";
      for(auto d2:d){
         // int breite = d2.size();
         int dame_pos = d2;
         for(int i=0; i < d.size(); i++) {
            if(i==dame_pos)
               cout << "D";
            else
               cout << "-";
         }
         cout << endl;
      }
   }
}
int main(int argc, char *argv[]) {
   /*
   if(argc == 2) {
      int n_damen = (int) *argv[1];
      cout << n_damen;
   }
   */
   vector<vector<int>> damen = damen_problen(6,6);
   print_board(damen);
   return EXIT_SUCCESS;
}