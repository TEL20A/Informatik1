#include <iostream>
#include <string>
#include <cstdlib>

#include <vector>

using namespace std;

// Erwartet eine Länge und einen String mit erlaubten Zeichen.
// Liefert ein zufallsgeneriertes Passwort mit der gegebenen Länge zurück.
string passwort(int laenge, string erlaubte_zeichen) {
  
  // String für das Ergebnis
  string p = "";

/*
  // Nicht falsch, aber auch nicht notwendig:
  // Den Zeichen-String in einen Vektor kopieren.
  vector<char> v(
    erlaubte_zeichen.begin(),
    erlaubte_zeichen.end()
  );
*/

  // Schleife bis gewünschten Länge
  for (int i = 0; i <= laenge-1; i++) {
     // Zufällige Position im Zeichenstring wählen...
     int r = rand() % erlaubte_zeichen.size();
     // ... und an das Ergebnis anhängen.
     //p = p + v[r]; // Spezialversion für Strings
     p.push_back(erlaubte_zeichen[r]);
  }
  
  return p;
}

int main() {
  // Zufallsgenerator initialisieren (genau einmal!)
  srand(time(nullptr));

  // Den Benutzer nach der Länge seines gewünschten Passworts fragen.
  cout << "Wie lang soll das Passwort sein? ";
  int laenge;
  cin >> laenge;

  // Den Passwortgenerator aufrufen.
  string p = passwort(laenge, "1234567890");

  // Das Passwort anzeigen.
  cout << "Das neue Passwort lautet: " << p << endl;
}





