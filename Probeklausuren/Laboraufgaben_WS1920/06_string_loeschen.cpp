#include "pruefung.h"

/*** AUFGABE: Strings, 6 Punkte ***/

/*** AUFGABENSTELLUNG:
     Schreiben Sie eine Funktion 'loeschen', die als Argumente einen
     String s und einen Buchstaben c erwartet.
     Die Funktion soll jedes zweite Vorkommen von c in s l�schen und das
     Ergebnis zur�ckliefern.
     
	 D.h. das erste Vorkommen von c soll erhalten bleiben, das zweite
	 gel�scht werden, das dritte erhalten etc.
***/
string loeschen(string s, char c);

/*** TESTCODE/MAIN: ***/
int main()
{
    cout << loeschen("abcbd", 'b') << endl;       // Soll "abcd" ausgeben.
    cout << loeschen("abcbdbabe", 'b') << endl;   // Soll "abcdbae" ausgeben.
    
    return 0;
}

