#include "pruefung.h"

/*** AUFGABE: Sieb des Eratosthenes ***/

/*** AUFGABENSTELLUNG:
    Schreiben Sie eine Funktion sieve, die eine Liste von Zahlen und eine Zahl n erwartet.
    
    Die Funktion soll alle Vielfachen von n aus der Liste löschen.
    n selbst soll in der Liste bleiben, falls es vorkommt.
    Dann soll die Funktion das Ergebnis liefern.

    Zusatzaufgabe:
    Schreiben Sie eine Funktion primes, die eine Liste von positiven Zahlen erwartet und die nur die Primzahlen in dieser Liste übrig lässt.
    Sie können sieve dafür benutzen und dürfen annehmen, dass die Liste keine 1 enthält.
***/
vector<int> sieve(vector<int> liste, int n);
vector<int> primes(vector<int> liste);

/*** TESTCODE/MAIN ***/
int main() {
    
    vector<int> v1 = {2,3,4,5,6,7,8,9,10};
    print(sieve(v1,2));   // Soll 2 3 5 7 9 ausgeben.
    print(sieve(v1,3));   // Soll 2 3 4 5 7 8 10 ausgeben.

    vector<int> v2 = {1,2,3,4,5,6,7,8,9,10};
    print(sieve(v2,1));   // Soll 1 ausgeben.
    
    vector<int> v3 = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    print(primes(v3));   // Soll 2 3 5 7 11 13 17 19 ausgeben.

    return 0;
}
