#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Diese Funktion soll prüfen ob ein bestimmtes Feld frei ist
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

// Diese Funktion soll eine Dame in einer Reihe platzieren
// Dabei geht die Funktion durch die Reihe und prüft jede Spalte
// Es werden alle vorherigen Lösungen gespeichert, wenn eine Reihe mit einem
// Teil des Lösungsbaums keinen freien Platz mehr findet wird er nicht mehr zurück gegeben
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
      // Abbruch Bedingung
      vector<vector<int>> damen = {{}};
      return damen;
   }
   else {
      // Rekursion
      return platziere_dame(reihen-1, spalten, damen_problen(reihen-1,spalten));
   }
}


void print_board(vector<vector<int>> &damen) {
   for(auto d:damen) {
      cout << "\nLoesung: \n";
      for(auto d2:d){
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
   if (damen.size() > 0) {
      int length = damen[0].size(); // Größe des ersten Feldes
      cout  << "Es gibt " << damen.size()
            << " verschiedene Lösungen für ein Feld von "
            << length << " x " << length << endl;
   }
   else {
      cout << "Für dieses Feld gibt es keinen Lösungen\n";
   }
}
int main(int argc, char *argv[]) {
   int n_damen = 8;
   if(argc == 2) {
      n_damen = atoi(argv[1]);
   }
   vector<vector<int>> damen = damen_problen(n_damen, n_damen);
   print_board(damen);
   return EXIT_SUCCESS;
}