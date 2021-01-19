# Labor vom 08.01.2021

Hier sind die Aufgaben sowie Beispiele zu Pointern aus dem Labor mit Lösungen.
[Link zum Repl.it](https://repl.it/join/lrjfezgq-toj11001)


## Auführen des Programms:

- Kompilieren: `make`
- Starten (+Kompilieren): `make run`
- Output löschen: `make clean`

## Mögliche Übungen:

***In TicTacToe:***
- Lösungsweg mit globalen Variablen anstatt die Nutzung von Referenzen.
- Verwenden der Pointer Arithmetik anstatt die Nutzung von Referenzen:
  -  z.B. bei `void print_board(vector<string>* board)`einen Pointer verwenden. Pointer bei einem Vector sind aber etwas kompliziert
  -  Einfacher: Anstatt bei `char player` nur den Wert zu übergeben einen Pointer verweden `char* player`
- Auslagern von einzelnen Funktionen in ein neue `*.cpp` Datei mit dazugehöriger Header Datei `*.h`


***Bei den Pointer Beispielen:***
- Zusätzliche Implementierung der `findmin(...)` Funktion mit Rückgabetyp Pointer `double * findminptr(double * dfeld,int laenge)`. Etwas schwieriger: Verwendung der Pointer Schreibweise für c-arrays und Benutzung der Addresse zum durchlaufen des arrays `ptr++`
