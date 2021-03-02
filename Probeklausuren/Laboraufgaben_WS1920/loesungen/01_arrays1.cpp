/*** AUFGABE: Arrays ***/ 
/*** PUNKTE: 4 ***/

/*** INCLUDES: ***/
#include "pruefung.h"

/*** AUFGABENSTELLUNG:
    Schreiben Sie eine Funktion multodd, die eine Liste von Zahlen erwartet.
    
    Die Funktion soll das Produkt der Elemente an ungeraden Positionen zurückliefern.
    Die Position 0 ist gerade.
***/
int multodd(vector<int> liste);


/*** TESTCODE/MAIN: ***/
int main() {
    
    vector<int> v1 = {1,2,3,4,5};        // Produkt: 2*4 = 8
    cout << multodd(v1) << endl;         // Soll 8 ausgeben
    
    vector<int> v2 = {5,4,3,2,1};        // Produkt: 4*2 = 8
    cout << multodd(v2) << endl;         // Soll 8 ausgeben
    
    vector<int> v3 = {3,29,0,42,2,38};   // Produkt: 29*42*38 = 46284
    cout << multodd(v3) << endl;         // Soll 46284 ausgeben
    
    vector<int> v4 = {38};               // Keine ungeraden Positionen, daher 1.
    cout << multodd(v4) << endl;         // Soll 1 ausgeben
    return 0;
}

/*** LOESUNG: ***/
int multodd(vector<int> liste)
{
    int result = 1;
    for (int i=1; i<liste.size(); i+=2)
    {
        result *= liste[i];
    }
    
    return result;
}

