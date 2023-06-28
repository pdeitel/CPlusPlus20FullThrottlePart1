// Control Statements Snippets
#include <iostream>
using namespace std;

int main() {
   // if   
   int grade1{75};

   if (grade1 >= 60) {
      cout << "Passed\n";
   }


   // if...else
   int grade2{55};
    
   if (grade2 >= 60) {
      cout << "Passed\n";
   } 
   else {
      cout << "Failed\n"; 
   }


   // nested if...else
   int grade3{75};
    
   if (grade3 >= 90) {
      cout << "A\n";
   } 
   else { 
      if (grade3 >= 80) {
         cout << "B\n"; 
      } 
      else { 
         if (grade3 >= 70) {
            cout << "C\n"; 
         } 
         else { 
            if (grade3 >= 60) {
               cout << "D\n"; 
            } 
            else { 
               cout << "F\n"; 
            } 
         } 
      } 
   }


   // nested if...else
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


   // conditional operator
   int grade5{75};
   cout << (grade5 >= 60 ? "Passed\n" : "Failed\n");


   // while iteration statement
   int product{3}; 

   while (product <= 100) { 
      product = 3 * product; 
   }

   cout << product << "\n";
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

