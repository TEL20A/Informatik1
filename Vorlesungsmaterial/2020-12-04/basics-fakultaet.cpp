#include <iostream>
using namespace std;

int factorial(int n) {
  int ergebnis = 1;
  for(int i = 2; i <= n; i = i + 1) {
    ergebnis = ergebnis * i;
  }
  return ergebnis;
}

int main() {
  int x;  // Deklaration einer Variablen vom Typ int,
          // d.h. eine Variable, die ganze Zahlen
          // speichern soll.
  
  x = 42; // Zuweisung der Zahl 42 an die Variable x.
  cout << x << endl;
  
  x = 23;
  cout << x << endl; // "endl" -> "endline"

  // Fakultät von 5
  int f1 = 1 * 2 * 3 * 4 * 5;
  cout << "Fakultaet von 5 (f1):\n" << f1 << endl;

  // Fakultät von 5 Schrittweise berechnet:
  // Variable f2        Zwischenergebnis
  int f2 = 1;           // 1
  f2 = f2 * 2;          // 2
  f2 = f2 * 3;          // 6
  f2 = f2 * 4;          // 24
  f2 = f2 * 5;          // 120
  cout << "Fakultaet von 5 (f2):\n" << f2 << endl;

/*
  int n;
  cout << "Von welcher Zahl soll die Fakultaet berechnet werden? ";
  cin >> n;
  int f3 = factorial(n);
  cout << "Fakultaet von " << n << " (f3):\n" << f3 << endl;
*/

  cout << "Fakultaet von 3:" << factorial(3) << endl;
  cout << "Fakultaet von 5:" << factorial(5) << endl;
  cout << "Fakultaet von 7:" << factorial(7) << endl;
  cout << "Fakultaet von 9:" << factorial(9) << endl;

  return 0;
}



// Aufgaben (siehe separates Aufgaben-Repo auf GitHub)

// Schreiben Sie eine Funktion, die als Parameter eine Zahl n erwartete, und die die Summe der Zahlen von 1 bis n zurückgibt.


// Schreiben Sie eine Funktion, die den Benutzer so lang nach Zahlen fragt, bis er ein 0 eingibt. Anschließend soll die Summe der eingegebenen Zahlen ausgegeben werden.






