// fig08_10.cpp
// Creating a sequential file.
// Modified for full-throttle presentation purposes.
#include <cstdlib> // exit function prototype              
#include <format> 
#include <fstream> // contains file stream processing types
#include <iostream>
#include <string>

int main() {
   // ofstream opens the file  
   std::ofstream output{"clients.txt", std::ios::out};

   if (!output) {
      std::cerr << "File could not be opened\n";
      std::exit(EXIT_FAILURE);
   }

   output << std::format("{} {} {}\n", 100, "Devi", 24.98);
   output << std::format("{} {} {}\n", 200, "Taylor", 345.67);
   output << std::format("{} {} {}\n", 300, "Huber", 0.00);
   output << std::format("{} {} {}\n", 400, "Karimov", -42.16);
   output << std::format("{} {} {}\n", 500, "Sosa", 224.62);
}


/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
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
