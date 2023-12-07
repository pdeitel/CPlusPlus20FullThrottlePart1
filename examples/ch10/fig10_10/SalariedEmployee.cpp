// Fig. 10.2: SalariedEmployee.cpp
// Class SalariedEmployee member-function definitions.
#include <format>
#include <stdexcept>
#include "SalariedEmployee.h" // SalariedEmployee class definition

// constructor                                                        
SalariedEmployee::SalariedEmployee(std::string_view name, double salary)
   : m_name{name} {

   if (salary < 0.0) {
      throw std::invalid_argument("Salary must be >= 0.0");
   }

   m_salary = salary;
}

// calculate earnings                        
double SalariedEmployee::earnings() const {return m_salary;}

// return string representation of SalariedEmployee object        
std::string SalariedEmployee::toString() const {                       
   return std::format("name: {}\nsalary: ${:.2f}\n", 
      m_name, m_salary);
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
