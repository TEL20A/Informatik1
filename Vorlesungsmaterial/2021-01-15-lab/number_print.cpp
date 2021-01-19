#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// global variables
vector<string> einer = {
    "Null", "Eins", "Zwei",
    "Drei", "Vier", "Fünf",
    "Sechs", "Sieben", "Acht",
    "Neun"};

void print_zehner(int &&zahl, std::string str);
void print_einer(const int &zahl);
void print(std::string str);
void zahl_ausgeben(const int &zahl);
void test_output();

int main(int argc, char *argv[])
{
   int zahl;
   cout << "Bitte eine Zahl zwischen 0 und 100 eingeben: \n";
   cin >> zahl;

   zahl_ausgeben(zahl);
   test_output();
   return EXIT_SUCCESS;
}

void test_output()
{
   for (int i = 0; i <= 100; i++)
   {
      zahl_ausgeben(i);
   }
}

void zahl_ausgeben(const int &zahl)
{
   if (zahl < 10)
   {
      print_einer(zahl);
   }
   else if (zahl >= 10 && zahl < 20)
   {
      switch (zahl)
      {
      case 10:
         print("Zehn");
         break;
      case 11:
         print("Elf");
         break;
      case 12:
         print("Zwölf");
         break;
      default:
         print(einer[zahl-10]+"zehn");
         break;
      }
   }
   else if (zahl >= 20 && zahl < 30)
   {
      if (zahl == 20)
      {
         print("Zwanzig");
      }
      else
      {
         print_zehner(zahl - 20, "zwanzig");
      }
   }
   else if (zahl >= 30 && zahl < 40)
   {
      zahl == 30 ? print("Dreißig") : print_zehner(zahl - 30, "dreißig");
   }
   else if (zahl >= 40 && zahl < 50)
   {
      zahl == 40 ? print("Vierzig") : print_zehner(zahl - 40, "vierzig");
   }
   else if (zahl >= 50 && zahl < 60)
   {
      zahl == 50 ? print("Fünfzig") : print_zehner(zahl - 50, "Fünfzig");
   }
   else if (zahl >= 60 && zahl < 70)
   {
      zahl == 60 ? print("Sechsig") : print_zehner(zahl - 60, "Sechsig");
   }
   else if (zahl >= 70 && zahl < 80)
   {
      zahl == 70 ? print("Siebzig") : print_zehner(zahl - 70, "siebzig");
   }
   else if (zahl >= 80 && zahl < 90)
   {
      zahl == 80 ? print("Achtzig") : print_zehner(zahl - 80, "achtzig");
   }
   else if (zahl >= 90 && zahl < 100)
   {
      zahl == 90 ? print("Neunzig") : print_zehner(zahl - 90, "neunzig");
   }
   else if (zahl >= 90 && zahl < 100)
   {
      print("Hundert");
   }
}

void print_zehner(int &&zahl, std::string str)
{
   switch (zahl)
   {
   case 1:
      print("Einund" + str);
      break;
   case 2:
      print("Zweinund" + str);
      break;
   case 3:
      print("Dreiund" + str);
      break;
   case 4:
      print("Vierund" + str);
      break;
   case 5:
      print("Fünfund" + str);
      break;
   case 6:
      print("Sechsund" + str);
      break;
   case 7:
      print("Siebenund" + str);
      break;
   case 8:
      print("Achtund" + str);
      break;
   case 9:
      print("Neunund" + str);
      break;

   default:
      print("Fehlt" + str);
      break;
   }
}
void print_einer(const int &zahl)
{
   print(einer[zahl]);
}
void print(std::string str)
{
   cout << str << endl;
}