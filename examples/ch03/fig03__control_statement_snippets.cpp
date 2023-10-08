// Control Statements Snippets
#include <iostream>
using namespace std;

int main() {
   cout << "if statement result:\n";
   
   int grade1{75};

   if (grade1 >= 60) {
      cout << "Passed\n";
   }


   cout << "\nif...else statement result:\n";
   int grade2{55};
    
   if (grade2 >= 60) {
      cout << "Passed\n";
   } 
   else {
      cout << "Failed\n"; 
   }


   cout << "\nconditional expression result:\n";
   int grade3{75};
   cout << (grade3 >= 60 ? "Passed\n" : "Failed\n");


   cout << "\nnested if...else statement result:\n";
   int grade4{75};
    
   if (grade4 >= 90) {
      cout << "A\n";
   } 
   else if (grade4 >= 80) {
      cout << "B\n"; 
   } 
   else if (grade4 >= 70) {
      cout << "C\n"; 
   } 
   else if (grade4 >= 60) {
      cout << "D\n"; 
   } 
   else { 
      cout << "F\n"; 
   } 


   cout << "\nwhile iteration statement result:\n";
   int product{3}; 

   while (product <= 100) { 
      product = 3 * product; 
   }

   cout << "First power of 3 greater than 100: " << product << "\n";
}





/**************************************************************************
 * (C) Copyright 1992-2023 by Deitel & Associates, Inc. and               *
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

