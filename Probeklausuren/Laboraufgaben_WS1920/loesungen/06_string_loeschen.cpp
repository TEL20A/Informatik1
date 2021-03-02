/*** AUFGABE: Strings ***/
/*** PUNKTE: 6 ***/

/*** INCLUDES: ***/
#include "pruefung.h"

/*** AUFGABENSTELLUNG:
  Schreiben Sie eine Funktion 'loeschen', die als Argumente einen
  String s und einen Buchstaben c erwartet.
  Die Funktion soll jedes zweite Vorkommen von c in s löschen und das
  Ergebnis zurückliefern.
  
  D.h. das erste Vorkommen von c soll erhalten bleiben, das zweite
  gelöscht werden, das dritte erhalten etc.
***/
string loeschen(string s, char c);

/*** TESTCODE/MAIN: ***/
int main()
{
    /// TESTFALL: Soll "abcd" ausgeben.
    cout << loeschen("abcbd", 'b') << endl;
    
    /// TESTFALL: Soll "abcdbae" ausgeben.
    cout << loeschen("abcbdbabe", 'b') << endl;
    
    return 0;
}

/*** LOESUNG: ***/
string loeschen(string s, char c)
{
	int zaehler = 0;
	string ergebnis;
	for (char el : s) {
		if (el == c)
		{
			zaehler++;
		}
		if (el != c || zaehler % 2 != 0)
		{
			ergebnis.push_back(el);
		}
	}
	return ergebnis;
}