#include "pruefung.h"

/*** AUFGABE: Arrays, 4 Punkte ***/

/*** AUFGABENSTELLUNG:
    Schreiben Sie eine Funktion zip, die zwei Strings erwartet.

    Die Funktion soll die beiden Strings zusammenmischen, indem Sie
    immer abwechselnd ein Zeichen aus dem einen und dem anderen nimmt.
    Sie dürfen annehmen, dass die Strings gleich lang sind.

    Die Funktion soll das Ergebnis zurückliefern.
***/
string zip(string s1, string s2);


/*** TESTCODE/MAIN ***/
int main() {
    
    cout << zip("abc", "def") << endl; // Soll "adbecf" ausgeben.
    cout << zip("bab", "aba") << endl; // Soll "baabba" ausgeben.
    cout << zip("", "") << endl; // Soll "" ausgeben.
    return 0;
}
