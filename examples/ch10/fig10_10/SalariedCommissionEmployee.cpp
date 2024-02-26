// Fig. 10.5: SalariedCommissionEmployee.cpp
// Class SalariedCommissionEmployee member-function definitions.
#include <format>
#include <stdexcept>
#include "SalariedCommissionEmployee.h"

// constructor
SalariedCommissionEmployee::SalariedCommissionEmployee(
   std::string_view name, double salary, double grossSales, 
   double commissionRate)
   : SalariedEmployee{name, salary} { // call base-class constructor 

   if (grossSales < 0.0) {
      throw std::invalid_argument("Gross sales must be >= 0.0");
   }

   if (commissionRate <= 0.0 || commissionRate >= 1.0) {
      throw std::invalid_argument(
         "Commission rate must be > 0.0 and < 1.0");
   }

   m_grossSales = grossSales;
   m_commissionRate = commissionRate;
}

// calculate earnings--uses SalariedEmployee::earnings()
double SalariedCommissionEmployee::earnings() const {
   return SalariedEmployee::earnings() + 
      m_grossSales * m_commissionRate;
} 

// returns string representation of SalariedCommissionEmployee object
std::string SalariedCommissionEmployee::toString() const {
   return std::format(
      "{}gross sales: ${:.2f}\ncommission rate: {:.2f}\n",
      SalariedEmployee::toString(), m_grossSales, m_commissionRate);
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
