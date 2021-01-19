#include <iostream>

enum sex_type
{
   mann,
   frau,
   divers
};
enum struct noten
{
   sehr_gut = 1,
   gut,
   befriedigend,
   ausreichend,
   mangelhaft,
   ungenuegend
};

void note_berechnen(noten Note)
{
   switch (Note)
   {
   case noten::sehr_gut:
      std::cout << "Note Sehr gut\n";
      break;
   case noten::gut:
      std::cout << "Note Gut\n";
      break;
   case noten::befriedigend:
      std::cout << "Note Befriedigend\n";
      break;

   default:
      std::cout << "Note nicht gefunden\n";
      break;
   }
}

int main()
{
   enum Color
   {
      red,
      green,
      yellow
   };
   enum struct Color2
   {
      red,
      green,
      yellow,
      blue
   };
   Color mycolor = green;
   switch (mycolor)
   {
   case red:
      std::cout << "red\n";
      break;
   case Color::green:
      std::cout << "green\n";
      break;
   default:
      std::cout << "default\n";
      break;
   }

   Color2 my_scoped_color = Color2::green;
   switch (my_scoped_color)
   {
   case Color2::red:
      std::cout << "scoped red\n";
      break;
   case Color2::green:
      std::cout << "scoped green\n";
      break;
   default:
      std::cout << "default\n";
      break;
   }

   struct person
   {
      std::string name;
      int alter;
      enum sex_type geschlecht;

      void print()
      {
         std::cout << name << alter;
      }
   };

   struct person A;
   A.alter = 25;
   A.name = "student1";
   A.geschlecht = mann;

   std::cout << "A.name: " << A.name << std::endl;
   std::cout << "A.alter: " << A.alter << std::endl;
   std::cout << "A.ge: " << A.geschlecht << std::endl;

   noten Note = noten::gut;
   note_berechnen(Note);

   return EXIT_SUCCESS;
}