#include <iostream>
using namespace std;

int foo()
{
  int x = 3;
  return 0;
  x = x + 39;
  return x;
}

int main() {

  int k = foo();


  
  cout << k << endl;

  return 0;
}