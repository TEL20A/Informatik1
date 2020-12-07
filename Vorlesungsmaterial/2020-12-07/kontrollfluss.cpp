#include <iostream>
using namespace std;





// Berechnet die Fakultät von n
// ... mit einer for-Schleife
int factorial1(int n) {
  int ergebnis = 1;
  for (int i = 2; i <= n; i++) {
    ergebnis = ergebnis * i;
  }
  return ergebnis;
}

// Berechnet die Fakultät von n
// ... mit einer while-Schleife
int factorial2(int n) {
  int ergebnis = 1;
  int i = 2;
  while (i <= n) {
    ergebnis = ergebnis * i;
    i++;
  }
  return ergebnis;
}


int factorial3(int n) {
  if (n == 0) { return 1; }
  else { return factorial3(n-1) * n; }
}

// TODO
int sum0(){
  int n = 1;
  int ergebnis = 0;
  while(n!=0){
    cout << "Erneut eine Zahl eingeben: " <<endl;
    cin >> n;
    ergebnis = ergebnis + n;
  }
  cout << "Summe der eingegeben Zahlen: " << endl; 
  return ergebnis;
}






int main() {
  cout << "Fakultaet von 3: " << factorial3(5) << endl;
  //cout << factorial1(factorial1(3)) << endl;
 
  //cout << sum0() << endl;
 /*
 {
  int x,y;
  x = 1;
  y=0;
  
  while (x!=0)
  {
    cout << "Geben sie eine Zahl ein" << endl;
    cin >> x;
    y=y+x;
  } 
    cout << "Die Summe ist: " << y << endl;
  }
  */


  return 0;
}



// Aufgaben (siehe separates Aufgaben-Repo auf GitHub)

// Schreiben Sie eine Funktion, die als Parameter eine Zahl n erwartet, und die die Summe der Zahlen von 1 bis n zurückgibt.









