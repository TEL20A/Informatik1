# Aufgaben zu Sortierverfahren

In der letzten Vorlesung wurden zwei Sortierverfahren besprochen: `BubbleSort` und `SelectionSort`. Diese Verfahren sollen im Rahmen dieses Labors implementiert werden. Dabei soll schrittweise vorgegangen werden, d.h. es sollen zuerst verschiedene Hilfsfunktionen programmiert und diese dann zu einer Lösung zusammengesetzt werden.

## BubbleSort

Idee des Verfahrens ist es, beginnend beim Anfang der Liste, immer ein Element mit seinem rechten Nachbarn zu vergleichen und zu vertauschen, wenn diese nicht richtig sortiert sind. Als erstes vergleicht man die Elemente an den Stellen `0` und `1`, danach an den Stellen `1` und `2`, Stellen `2` und `3` usw., bis zum Ende der Liste. Wenn die Liste `n` Elemente hat, also bis zu den Stellen `n-1` und `n`.

Sobald man auf diese Weise einmal durch die Liste gelaufen ist, steht auf jeden Fall das größte Element am Ende. Auch andere Elemente können nach rechts gewandert sein, falls sie größer als ihre Nachbarn waren. Wiederholt man dies `n` mal, so ist die Liste sortiert.

### Hilfsfunktionen
Um `BubbleSort` zu implementieren entwickeln wir nacheinander die folgenden Funktionen.

- `void swap(vector<int> & v, int i, int j);`  
  Soll im Vektor `v` die Elemente an den Stellen `i` und `j` miteinander vertauschen.
- `void compare_and_swap(vector<int> & v, int i, int j);`  
  Soll im Vektor `v` die Elemente an den Stellen `i` und `j` miteinander vergleichen und sie vertauschen, falls sie falsch herum sortiert sind. 
- `void bubble_up(vector<int> & v);`  
  Soll im Vektor `v` einen Durchlauf wie oben beschrieben machen, so dass größere Elemente Richtung Ende wandern.
- `void bubblesort(vector<int> & v);`  
  Soll den Vektor `v` mit dem Verfahren `BubbleSort` sortieren.

**Anmerkungen:**

- Jede der obigen Funktionen erwartet einen `vector<int>` als Referenz(`&`). Diese Referenz ist notwendig, damit das Verfahren überhaupt einen Effekt hat. Ohne das Referenzzeichen würde nur eine Kopie des Vektors aus dem Hauptprogramm bearbeitet werden.
- Jede der obigen Funktionen kann mit Hilfe der jeweils vorherigen geschrieben werden.
Eine solche Modularisierung ist sinnvoll, um Struktur/Konzept übersichtlich zu halten. Dies erleichtert die Entwicklung und auch die spätere Wartung des Codes.
- Die einzelnen Funktionen sollten möglichst kurz sein. Lange Funktionen kommen gelegentlich beim Entwickeln vor, sollten aber immer ein Warnsignal sein bzw. ein Hinweis, dass möglicherweise noch Struktur fehlt.


## SelectionSort

Idee des Verfahrens ist es, die zu sortierende Liste in einen schon sortierten und einen noch unsortierten Teil zu zerlegen.
Der sortierte Teil steht links vom unsortierten und ist am Anfang leer.
In mehreren Durchläufen wird nun jeweils das kleinste Element im noch unsortierten Teil gesucht und an den Anfang (des unsortierten Teils) getauscht.
Dadurch wird der sortierte Teil um ein Element größer und der unsortierte Teil kleiner.
Wiederholt man dies `n` Mal (bei `n` Elementen), so ist die Liste sortiert.

### Hilfsfunktionen
Auch für `SelectionSort` entwickeln wir wieder eine Reihe von Hilfsfunktionen:

- `void swap(vector<int> & v, int i, int j);`  
  Soll im Vektor `v` die Elemente an den Stellen `i` und `j` miteinander vertauschen.
- `int select(vector<int> & v, int i);`  
  Soll im Vektor `v` ab Stelle `i` das kleinste Element suchen und dessen Position zurückgeben.
- `void selectionsort(vector<int> & v);`  
  Soll den Vektor `v` mit dem Verfahren `SelectionSort` sortieren.
  
## Aufgaben

- Entwickeln Sie die Sortiertfunktion `bubblesort()`, indem Sie nacheinander die obigen Hilfsfunktionen schreiben und dabei jeweils möglichst die vorherigen Funktionen nutzen.
Die Funktion soll einen `int`-Vektor aufsteigend sortieren.
- Entwickeln Sie die Sortiertfunktion `selectionort()`, indem Sie nacheinander die obigen Hilfsfunktionen schreiben und dabei jeweils die vorherigen Funktionen nutzen, soweit das sinnvoll ist.
Die Funktion soll einen `int`-Vektor aufsteigend sortieren.
- Erweitern/verändern Sie Ihre Sortierverfahren:
  - Die Listen sollen absteigend sortiert werden.
  - Anstelle von Zahlen sollen Strings sortiert werden ...
  - ... oder Paare von Strings (Datentyp `vector<pair<string, string>>`).  
    Machen Sie sich dafür mit dem Datentyp `std::pair` vertraut und überlegen Sie sich,
    wie man so einen Vektor aus Paaren von Strings z.B. für die Implementierung eines 
    einfachen Wörterbuchs nutzen kann.