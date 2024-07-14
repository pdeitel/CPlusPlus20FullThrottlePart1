// Control Statements Snippets
#include <iostream>

int main() {
   std::cout << "if statement result:\n";
   
   int grade1{75};

   if (grade1 >= 60) {
      std::cout << "Passed\n";
   }


   std::cout << "\nif...else statement result:\n";
   int grade2{55};
    
   if (grade2 >= 60) {
      std::cout << "Passed\n";
   } 
   else { // some people prefer to "cuddle" this after the } above
      std::cout << "Failed\n";
   }


   std::cout << "\nconditional expression result:\n";
   int grade3{75};
   std::cout << (grade3 >= 60 ? "Passed\n" : "Failed\n");


   std::cout << "\nnested if...else statement result:\n";
   int grade4{75};
    
   if (grade4 >= 90) {
      std::cout << "A\n";
   } 
   else if (grade4 >= 80) {
      std::cout << "B\n";
   } 
   else if (grade4 >= 70) {
      std::cout << "C\n";
   } 
   else if (grade4 >= 60) {
      std::cout << "D\n";
   } 
   else { 
      std::cout << "F\n";
   } 

   std::cout << "\nwhile iteration statement result:\n";
   int product{3}; 

   while (product <= 100) { 
      product = 3 * product; 
   }

   std::cout << "First power of 3 greater than 100: " << product << "\n";
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

