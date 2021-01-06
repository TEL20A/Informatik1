#include <iostream>

using namespace std;

void foo(int x)
{
   x += 42;
   int y = 146;
   cout << x << ' ' << y << endl;
}
int main()
{
   int x = 42;
   int y = 23;
   cout << x << ' ' << y << endl;
   foo(x);
   cout << x << ' ' << y << endl;
   for (int y = 0; y < 5; y++)
   {
      int x = y * 2;
      cout << x;
   }
   cout << x << endl;
   return 0;
}