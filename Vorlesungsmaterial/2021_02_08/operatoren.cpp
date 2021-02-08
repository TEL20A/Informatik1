#include <iostream>
#include <string>
using namespace std;

// Komplexe Zahlen sind von der Form a + bi
// D.h. sie bestehen aus zwei Komponenten:
// Dem Real- und dem Imaginärteil:
struct Complex
{
  double real = 0.0;
  double img = 0.0;

  string str() const
  {
    return to_string(real) + " + " + to_string(img) + "j";
  }
};

// Erwartet zwei Komplexe Zahlen als Parameter und die liefert deren Summe.
Complex add(Complex const & c1, Complex const & c2);
Complex operator+(Complex const & c1, Complex const & c2);

// Erwartet zwei Komplexe Zahlen als Parameter und die liefert deren Produkt.
Complex operator*(Complex const & c1, Complex const & c2);

// Erwartet zwei Komplexe Zahlen als Parameter und die liefert deren Quotienten.
Complex operator/(Complex const & c1, Complex const & c2);

ostream & operator<<(ostream & left, Complex const & c);

int main()
{
  Complex c1{1,3.1415};
  Complex c2{3,4};

  cout << c1.str() << endl;
  cout << c2.str() << endl;
  cout << (c1 + c2) << endl;
//  cout << add(c1,c2).str() << endl;

  cout << c1 << endl;

}

Complex add(Complex const & c1, Complex const & c2)
{
  return { c1.real + c2.real, c1.img + c2.img };
}

Complex operator+(Complex const & c1, Complex const & c2)
{
  return { c1.real + c2.real, c1.img + c2.img };
}

ostream & operator<<(ostream & left, Complex const & c)
{
  return left << c.str();
}