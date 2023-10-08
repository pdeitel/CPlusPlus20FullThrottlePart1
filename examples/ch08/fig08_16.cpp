// fig08_16.cpp
// Matching entire strings to regular expressions.
// Modified for full-throttle presentation purposes.
#include <format> 
#include <iostream>
#include <regex>

int main() {
   // fully match five digits
   std::regex pattern{R"(\d{5})"};
   std::cout << R"(Matching against: \d{5})" << "\n"
      << std::format("02215: {}\n9876: {}\n\n",
            std::regex_match("02215", pattern),
            std::regex_match("9876", pattern));
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
