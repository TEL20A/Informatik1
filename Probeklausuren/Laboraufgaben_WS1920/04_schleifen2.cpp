#include "pruefung.h"

/*** AUFGABE: Schleifen, 6 Punkte ***/

/*** AUFGABENSTELLUNG:
     
     Betrachten Sie die unten vorgegebene Funktion foo().
     Schreiben Sie eine Funktion bar() mit den folgenden
	 Eigenschaften:
     
     Für x >= 0 soll gelten: bar(foo(x)) == x.
     Für x < 0 soll gelten: bar(foo(x)) == -x.
     
     D.h. für positive x soll bar() den Effekt von foo()
     umkehren, für negative x soll sie das entsprechende
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


