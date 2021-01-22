# Modellierung und Programmierung eines Getränkeautomaten


|Der Automat hat eine bestimmte Anzahl an Erfrischungsgetränken unterschiedlicher Sorten. Der Automat verfügt über einen Geldeinwurf, ein Display zur Anzeige von Informationen, Knöpfe zur Getränkeauswahl und ein Ausgabefach.|<img src="https://www.dhuenn.com/wp/wp-content/uploads/2017/10/sandenvendo-g-drink-dm6-front.jpg" width="250"/>
|---|---
<br>

Funktionen/Methoden des Automats:
- `getraenkAuswaehlen(Getraenk);` List die Nutzerauswahl von der Konsole ein
- `getraenkAusgeben(Getraenk);`: Schreibt die Getränkeausgabe auf die Konsole
- `geldEinwerfen(int);`: Gibt dem Nutzer eine Auswähl an Münzen und liest
- `getPreis(Getraenk);`: gibt den Preis des Getraenks zurück
- `setPreis(int neuPreis, Getraenk);` : Wartungsmitarbeiter kann den Preis des ausgewählten Getränks verändern.

| Getränkeautomat Variablen | Tips
|---|---
| int getraenkeAnzahl | eventuell ein Vector von `int`, nicht vergessen es gibt verschiedene Sorten
| enum getraenkeSorte | könnte man z.B. als enum darstellen
| int getraenkePreis | Preis eines Getränks
| int geldImAutomat | Speichert das vorhandene Gekd im Automat
| int preis | Preis des Getränks
| int bezahlt | Bereits eingeworfenes Geld oder der noch fehlende Betrag


<br>
Es bietet sich an für den Automaten `structs` für die einzelnen Getränkeseorten zu erstellen um z.B. Preis, Anzahl, etc für die jeweilige Sorte zu speichern. Es geht aber auch ohne.