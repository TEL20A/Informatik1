#include <iostream>
#include <string>
using namespace std;

// Schreiben Sie eine Funktion anzahl_e, die einen String
// erwartet und die die Anzahl der Vorkommen des Buchstaben
// 'e' liefert.
int anzahl_e(string s)
{
  int anzahl = 0;

  // Jeden Buchstaben angucken, ob er ein e ist.
  for (int i=0; i< s.size(); i++)
  {
    if (s[i] == 'e')
    {
      anzahl++;
    }
  }

  return anzahl;
}


int main() {

  // Einen String definieren und ausgeben.
  string h = "Hello World!";
  std::cout << h << endl;

  // Ein einzelnes Zeichen ausgeben:
  char c = h[6];
  cout << c << endl;

  // Ein Zeichen anhängen.
  h.push_back('a');
  h.push_back(c);
  std::cout << h << endl;


  // h an der Stelle 1 soll ein a enthalten.
  h[1] = 'a';  // 'a' ist vom Typ char
  std::cout << h << endl;

  // Anmerkung:
  // h[1] bedeutet: Vom Anfang her um 1 nach rechts gehen,
  //                das ist dann der 2. Buchstabe.


  cout << anzahl_e("Hello") << endl;  // Soll 1 ausgeben.
  cout << anzahl_e("Hefe") << endl;   // Soll 2 ausgeben.
  cout << anzahl_e("Hallo") << endl;  // Soll 0 ausgeben.
}








