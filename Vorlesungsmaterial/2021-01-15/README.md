# Labor 15.01.21

- Vergleich der Performanz und Memory Nutzung von pass-by-reference vs. pass-by-value
- Programm zum Einlesen eines Integers (0-100) und dessen Ausgabe als String:
  - `25` --> `Fünfundzwanzig`
  - Unterschiedliche Schwierigkeitsgerade:
    - Zahlensystem auf Englisch ist einfacher.
    - Schwieriger mit Zahlen bis 1000 und auf Deutsch

## Hilfen:

- Benutzung der [`ctime` Bibliothek](https://www.cplusplusdASD.com/reference/ctime/clock/) zum messen der Zeit/CPU-Zyklen (`#include <ctime>`)

- Funktion zum Ausgeben der Memory Nutzung von Prozessen auf Linux Systemen
``` C++
#include <cstdlib>

void print_mem(std::string str="") {
  std::cout << str << std::endl;
  system("ps -o pid,user,%mem,command | sort -b -k3 | grep ./time.out");
}
```