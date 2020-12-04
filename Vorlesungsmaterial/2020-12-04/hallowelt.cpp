#include<iostream>  // Bibliothek für cout (s.u.)
using namespace std;

// Main-Funktion:
// Der Einstiegspunkt ins Programm.
// "Hier fängt das Programm an."
int main()  // Kopf der Funktion, das Programm liefert eine Zahl an das Betriebssystem zurück.
{
  // Den Benutzer nach seinem Namen fragen:
  cout << "Bitte geben Sie Ihren Namen ein: ";

  // Eine Variable für den Namen deklarieren:
  string name;

  // Den Namen einlesen:
  cin >> name;

  // Die Ausgabe des Namens
  cout << "Hallo " << name << "!" << endl;

  return 0;  // Ende mit Ergebnis 0.
}














