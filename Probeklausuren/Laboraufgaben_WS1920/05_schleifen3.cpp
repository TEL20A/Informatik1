#include "pruefung.h"

/*** AUFGABE: Schleifen, 4 Punkte ***/

/*** AUFGABENSTELLUNG:
     Schreiben Sie eine Funktion, die als Parameter zwei Buchstaben
     z1 und z2 erwartet.
     
     Die Funktion soll jeden zweiten Buchstaben im Alphabet
     auf der Konsole ausgeben, der zwischen z1 und z2 liegt.
     
     Genauer: Die Ausgabe soll beim übernächsten Buchstaben ab z1
	          beginnen. z1 und z2 selbst sollen nicht enthalten sein.
***/ 
void buchstaben(char z1, char z2);

/*** TESTCODE/MAIN: ***/
int main()
{
    buchstaben('a','z');   // Soll "c e g i k m o q s u w y" ausgeben.
    buchstaben('a','k');   // Soll "c e g i" ausgeben.
    buchstaben('a','d');   // Soll "c" ausgeben.
    buchstaben('b','a');   // Soll "" ausgeben.
    return 0;
}

