
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// global variables
const vector<string> einer = {
    "Null", "Eins", "Zwei",
    "Drei", "Vier", "Fünf",
    "Sechs", "Sieben", "Acht",
    "Neun"};
const vector<string> zehner_1 = {
    "Einund", "Zweinund", "Dreiund",
    "Vierund", "Fünfund", "Sechsund",
    "Siebenund", "Achtund", "Neunund"};
const vector<string> zehner_2 = {
    "zehn",
    "zwanzig",
    "dreißig",
    "vierzig",
    "fünfzig",
    "sechsig",
    "siebzig",
    "achtzig",
    "neunzig"};

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
         print(einer[zahl - 10] + "zehn");
         break;
      }
   }
   else if(zahl%10 == 0 && zahl < 100) { //Zahl ist durch 10 teilbar
      string str = zehner_2[zahl/10-1];
      str[0] = std::toupper(str[0]); //Ersten Buchstaben Groß schreiben
      print(str);
   }
   else if (zahl > 20 && zahl < 100)
   {
      print(zehner_1[zahl%10-1] + zehner_2[zahl/10-1]);
   }
   else if (zahl >= 100)
   {
      print("Hundert");
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