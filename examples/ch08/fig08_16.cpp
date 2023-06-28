// fig08_16.cpp
// Matching entire strings to regular expressions.
// Modified for full-throttle presentation purposes.
#include <format> 
#include <iostream>
#include <regex>

int main() {
   // fully match a pattern of literal characters
   std::regex r1{"02215"};
   std::cout << "Matching against: 02215\n"
      << std::format("02215: {}; 51220: {}\n\n",
            std::regex_match("02215", r1), std::regex_match("51220", r1));

   // fully match five digits
   std::regex r2{R"(\d{5})"};
   std::cout << R"(Matching against: \d{5})" << "\n"
      << std::format("02215: {}; 9876: {}\n\n",
            std::regex_match("02215", r2),
            std::regex_match("9876", r2));
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
