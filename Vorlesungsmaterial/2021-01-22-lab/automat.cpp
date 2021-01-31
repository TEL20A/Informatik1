#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum struct zustand {
  auswahl,
  bezahlen,
  ausgabe,
  ende,
  wartung
};
struct s_getraenk {
  string _name;
  int preis; // in cent
  short _anzahl;
};

//globale Variable
zustand state = zustand::auswahl;  //Initalzstuand automat
int getraenkeId;
vector<s_getraenk> getraenke = {
  {"Cola", 250, 0},
  {"Coke Zero", 250, 10},
  {"Fanta", 250, 15},
  {"Sprite", 250, 2},
  {"Wasser", 150, 2}
};

// Prototypen
void getraenkeAuswahl();
void zahlen();
void getraenkeAusgabe();
void wartungsModus();

int main() {
  //Zustandsautomat
  int eingabe;
  while(true) {
    switch(state) {
      case zustand::auswahl:
        getraenkeAuswahl();
        break;

      case zustand::bezahlen:
        zahlen();
        break;

      case zustand::ausgabe:
        getraenkeAusgabe();
        break;

      case zustand::ende:
        /* code hier */
        std::cout << "Automat fährt runter\n";
        return 0;
        break;

      case zustand::wartung:
        wartungsModus();
        break;

      default:
        break;
    }
  }
}

void getraenkeAuswahl(){
  int eingabe, i = 1;
  std::cout << "Ihre Auswahl bite:!\n";
  for (auto getr : getraenke) {
    cout << i << ": " << getr._name << ", Preis: " << getr.preis << " Cent" << endl;
    i++;
  }
  cout << "10: Programm beenden\n";
  cin >> eingabe;
  if(eingabe > 0 && eingabe <= getraenke.size()) {
    getraenkeId = eingabe - 1;
    // Check ob das Getränk verfügbar ist
    if(getraenke[getraenkeId]._anzahl > 0){
      state = zustand::bezahlen;
    }
    else {
      cout << "Es tut uns leider aber das Getränk ist zurzeit leider nicht verfügbar\nBitte treffen Sie eine andere Auswahl!\n";
    }
  }
  if(eingabe == 10) state = zustand::ende;

  // Wartungsmodus kann über eine nur dem Mitarbeiter
  // bekannte Kombination erreicht werden
  if(eingabe == 999) state = zustand::wartung;
}

void zahlen() {
  int eingabe;
  int zuZahlen = getraenke[getraenkeId].preis;
  cout << "Akzeptierte Geldmünzen:\n1: 2,00 EUR\n2: 1,00 EUR\n3: 0,50 EUR\n10: Zurück zur Getränkeauswahl\n";

  while (zuZahlen > 0) {
    cout << "Bitte werfen Sie " << zuZahlen <<" Cents in den Automaten\n";
    cin >> eingabe;
    switch (eingabe) {
      case 1:
        zuZahlen -= 200;
        break;
      case 2:
        zuZahlen -= 100;
        break;
      case 3:
        zuZahlen -= 50;
        break;
      case 10:
        state = zustand::auswahl;
        break;
      default:
        cout << "Eingabe nicht akzeptiert!" << endl;
        break;
    }
  }

  if(zuZahlen < 0) {
    cout << "Sie bekommen " << zuZahlen * -1 << " an Rückgeld\n";
  }
  state = zustand::ausgabe;
}

void getraenkeAusgabe() {
  getraenke[getraenkeId]._anzahl -= 1;
  cout << "Bitte entnehmen Sie Ihre " << getraenke[getraenkeId]._name << endl;
  state = zustand::auswahl;
}

void wartungsModus() {
  int eingabe;
  std::cout << "Willkommen im Wartungsmodus\n10: Zurück\n";
  cin >> eingabe;
  if(eingabe == 10) state = zustand::auswahl;
}