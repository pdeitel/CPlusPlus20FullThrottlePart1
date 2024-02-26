import std;

int main() {
   std::println("Demonstrating print and println");
   int total{385};
   std::cout << std::format("via std::format : Sum is {}\n", total);
   std::print("via std::print  : Sum is {}\n", total);
   std::println("via std::println: Sum is {}", total); 
   
   std::println("\nDemonstrating std::ranges::to\nfirst 5 even integers: ");
   auto isEven{ [](int x) {return x % 2 == 0;} };
   auto results{
      std::views::iota(0)
         | std::views::filter(isEven)
         | std::views::take(5)
         | std::ranges::to<std::vector>()};
   for (const auto& value : results) {
      std::cout << std::format("{} ", value);
   }

   std::println("\n\nDemonstrating std::views::zip");
   using namespace std::string_literals;
   std::vector names{ "Meriem"s, "Pierre"s, "Sierra"s };
   std::vector averages{ 3.9, 3.5, 4.0 };

   for (const auto& [name, gpa] : std::views::zip(names, averages)) {
      std::println("{}: {:.1f}", name, gpa);
   }

   std::println("\nDemonstrating std::views::enumerate");
   std::vector colors{ "red"s, "orange"s, "yellow"s };
   for (const auto& [i, color] : std::views::enumerate(colors)) { 
      std::println("{}: {}", i, color); 
   }

}


/**************************************************************************
 * (C) Copyright 1992-2024 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
