#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  // Beispiel für den Umgang mit Strings:

  // Einen String deklarieren
  string s = "Hallo C++";

  // s ausgeben
  cout << s << endl;

  // Jeden Buchstaben um 1 in der ASCII-Tabelle erhöhen
  for (int i=0; i<s.size(); i++)
  {
    s[i] = s[i] + 1;
  }

  // s noch einmal ausgeben
  cout << s << endl;


  // Beispiel für den Umgang mit Listen:

  // Eine Liste von Zahlen definieren
  vector<int> v1 = {1,7,9};

  // Die letzte Zahl verändern:
//  v1[4] = 38;

  // Eine Zahl anhängen
  v1.push_back(42);

  // v1 ausgeben
  for (int i=0; i< v1.size(); i++)
  {
    cout << v1[i] << endl;
  }

  // Eine Variable vom Typ bool erzeugebn
  // (hat die Werte "true" oder "false")
  bool b = false;

  // Den Wert von b auf true ändern, falls v1 länger als 5 ist.
  if (v1.size() > 5) { b = true; }
  cout << b << endl;
}






