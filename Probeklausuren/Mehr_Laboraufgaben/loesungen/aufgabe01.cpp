#include "pruefung.h"

/*** AUFGABE: Arrays ***/

/*** AUFGABENSTELLUNG:
    Schreiben Sie eine Funktion addNegative, die eine Liste von Zahlen erwartet.
    
    Die Funktion soll die Summe aller negativen Zahlen in der Liste liefern.
***/
int addNegative(vector<int> liste);


/*** TESTCODE/MAIN ***/
int main() {
    
    vector<int> v1 = {1,-2,3,-4,5};        
    cout << addNegative(v1) << endl;         // Soll -6 ausgeben
    
    vector<int> v2 = {-5,4,-3,-2,1};        
    cout << addNegative(v2) << endl;         // Soll -10 ausgeben
    
    vector<int> v3 = {3,29,0,-42,2,38};   
    cout << addNegative(v3) << endl;         // Soll -42 ausgeben
    
    vector<int> v4 = {38};               
    cout << addNegative(v4) << endl;         // Soll 0 ausgeben
    return 0;
}

/*** LOESUNG ***/
int addNegative(vector<int> liste)
{
  int result = 0;
  for (auto el : liste)
  {
    if (el < 0) { result += el; }
  }
  return result;
}
