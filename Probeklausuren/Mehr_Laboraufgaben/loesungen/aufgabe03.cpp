#include "pruefung.h"

/*** AUFGABE: Arrays ***/

/*** AUFGABENSTELLUNG:
    Schreiben Sie eine Funktion filter, die eine Liste von Zahlen und eine Zahl x erwartet.
    
    Die Funktion soll Zahlen in der Liste liefern, deren Betrag == x ist.
***/
vector<int> filter(vector<int> liste, int x);


/*** TESTCODE/MAIN ***/
int main() {
    
    vector<int> v1 = {1,-2,3,-4,5};        
    print(filter(v1,3));   // Soll 3 ausgeben.

    vector<int> v2 = {1,-2,3,-4,-3};
    print(filter(v2,3));   // Soll 3 -3 ausgeben.
    print(filter(v2,-3));   // Soll nichts ausgeben.

    vector<int> v3 = {1,-2,3,-4,-3};        
    print(filter(v3,4));   // Soll -4 ausgeben.
    print(filter(v3,5));   // Soll nichts ausgeben.

    return 0;
}

/*** LOESUNG ***/
vector<int> filter(vector<int> liste, int x)
{
  vector<int> result;
  
  for (auto el : liste)
  {
    int absel = el < 0 ? -el : el;
    if (absel == x) { result.push_back(el); } 
  }
  return result;
}
