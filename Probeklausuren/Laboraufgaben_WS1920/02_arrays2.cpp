#include "pruefung.h"

/*** AUFGABE: Arrays, 6 Punkte ***/

/*** AUFGABENSTELLUNG:
     Schreiben Sie eine Funktion, die als Parameter eine int Zahl n erwartet.
     
    Die Funktion soll einen zweidimensionalen int-Vektor mit n mal n Feldern
	zurückgeben, der in aufsteigender Reihenfolge die Zahlen von 1 bis n*n enthält.
***/
vector<vector<int>> zahlen(int n);

/*** TESTCODE/MAIN: ***/
int main()
{
    vector<vector<int>> v = zahlen(10);
    
    print_vector(v);
    /* So soll die Ausgabe aussehen:
    1 2 3 4 5 6 7 8 9 10
    11 12 13 14 15 16 17 18 19 20
    21 22 23 24 25 26 27 28 29 30
    ... 
    91 92 93 94 95 96 97 98 99 100
    */
    return 0;
}

