// fig04_06.cpp
// Using a switch statement to count letter grades.
#include <format>
#include <iostream>
using namespace std;

int main() {
   cout << "Enter an integer grade in the range 0-100: ";
   int grade;
   cin >> grade;
   cout << format("Letter grade for {} is: ", grade);

   // print letter grade 
   switch (grade / 10) {                        
      case 9:  // grade was between 90          
      case 10: // and 100, inclusive s           
         cout << "A\n";
         break; // exits switch                 
      case 8: // grade was between 80 and 89    
         cout << "B\n";
         break;
      case 7: // grade was between 70 and 79    
         cout << "C\n";
         break; // exits switch                 
      case 6: // grade was between 60 and 69    
         cout << "D\n";
         break; // exits switch                 
      default: // grade was less than 60        
         cout << "F\n";
         break; // optional; exits switch anyway
   } // end switch                              
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
 *************************************************************************/
