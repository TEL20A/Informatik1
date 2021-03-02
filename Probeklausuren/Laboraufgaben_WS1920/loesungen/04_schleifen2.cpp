/*** AUFGABE: Schleifen ***/
/*** PUNKTE: 6 ***/

/*** INCLUDES ***/
#include "pruefung.h"

/*** AUFGABENSTELLUNG:
     
     Betrachten Sie die unten vorgegebene Funktion foo().
     Schreiben Sie eine Funktion bar() mit den folgenden
	 Eigenschaften:
     
     F¸r x >= 0 soll gelten: bar(foo(x)) == x.
     F¸r x < 0 soll gelten: bar(foo(x)) == -x.
     
     D.h. f¸r positive x soll bar() den Effekt von foo()
     umkehren, f¸r negative x soll sie das entsprechende
     negative Ergebnis liefern.
***/
int bar(int x);


/*** VORGABE: ***/
int foo(int x)
{
    return x * x + 38;
}

/*** TESTCODE/MAIN: ***/
int main() {
    
    printf("%d\n",bar(foo(1)));           // Soll 1 ausgeben
    printf("%d\n",bar(foo(42)));          // Soll 42 ausgeben
    printf("%d\n",bar(foo(-2)));          // Soll 2 ausgeben
    printf("%d\n",bar(foo(0)));           // Soll 0 ausgeben
      
    return 0;
}

/*** LOESUNG: ***/
int bar(int x)
{
//	if (x<0) { return -bar(-x); }
	for (int i=1; i<x; i++)
	{
		if (i*i == x-38)
		{
			return i;
		}
	}
	return 0;
}


