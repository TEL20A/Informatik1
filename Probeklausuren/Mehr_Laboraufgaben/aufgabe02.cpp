#include "pruefung.h"

/*** AUFGABE: Permutationen eines Arrays ***/

/*** AUFGABENSTELLUNG:
    Schreiben Sie eine Funktion permutationen, die eine Liste von Zahlen erwartet.
    
    Die Funktion soll alle Permutationen der Liste liefern.
    D.h. eine Liste mit Vektoren, bei dem jeder einzelne Vektor eine Permutation (also eine Vertauschung) der Elemente ist.
***/
vector<vector<int>> permutationen(vector<int> liste);


/*** TESTCODE/MAIN ***/
int main() {
    
    vector<int> v1 = {1,2,3};
    print(permutationen(v1)); // Soll alle Varianten 1 2 3, 1 3 2, 2 3 1, ... ausgeben.
    
    return 0;
}


