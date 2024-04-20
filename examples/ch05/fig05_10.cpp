// fig05_10.cpp
// Overloaded square functions.
#include <iostream>

// function square for int values              
int square(int x) {
   std::cout << "square of integer " << x << " is ";
   return x * x;                               
} 

// function square for double values           
double square(double y) {
   std::cout << "square of double " << y << " is ";
   return y * y;                               
} 

int main() {
   std::cout << square(7); // calls int version
   std::cout << '\n';
   std::cout << square(7.5); // calls double version
   std::cout << '\n';
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
