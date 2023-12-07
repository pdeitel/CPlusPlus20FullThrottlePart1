// Fig. 11.5: MyArray.cpp
// MyArray class member- and friend-function definitions.
#include <algorithm>
#include <format>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <span>
#include <sstream>
#include <stdexcept>
#include <utility>
#include "MyArray.h" // MyArray class definition

// MyArray constructor that accepts an initializer list
MyArray::MyArray(std::initializer_list<int> list)
   : m_size{list.size()}, m_ptr{std::make_unique<int[]>(list.size())} {
   std::cout << "MyArray(initializer_list) constructor\n";

   // copy list argument's elements into m_ptr's underlying int array 
   // m_ptr.get() returns the int array's starting memory location
   std::copy(std::begin(list), std::end(list), m_ptr.get());
}

// copy constructor: must receive a reference to a MyArray
MyArray::MyArray(const MyArray& original)
   : m_size{original.size()},
     m_ptr{std::make_unique<int[]>(original.size())} {
   std::cout << "MyArray copy constructor\n";

   // copy original's elements into m_ptr's underlying int array 
   const std::span<const int> source{
      original.m_ptr.get(), original.size()};
   std::copy(std::begin(source), std::end(source), m_ptr.get());
}

// copy assignment operator: implemented with copy-and-swap idiom
MyArray& MyArray::operator=(const MyArray& right) {
   std::cout << "MyArray copy assignment operator\n";
   MyArray temp{right}; // invoke copy constructor
   swap(*this, temp); // exchange contents of this object and temp
   return *this;
}

// move constructor: must receive an rvalue reference to a MyArray                      
MyArray::MyArray(MyArray&& original) noexcept
   : m_size{std::exchange(original.m_size, 0)},
   m_ptr{std::move(original.m_ptr)} { // move original.m_ptr into m_ptr
   std::cout << "MyArray move constructor\n";
}

// move assignment operator
MyArray& MyArray::operator=(MyArray&& right) noexcept {
   std::cout << "MyArray move assignment operator\n";

   if (this != &right) { // avoid self-assignment  
      // move right's data into this MyArray
      m_size = std::exchange(right.m_size, 0); // indicate right is empty
      m_ptr = std::move(right.m_ptr);
   }

   return *this; // enables x = y = z, for example                    
}

// destructor: This could be compiler-generated. We included it here so
// we could output when each MyArray is destroyed.
MyArray::~MyArray() {
   std::cout << "MyArray destructor\n";
}

// return a string representation of a MyArray
std::string MyArray::toString() const {
   const std::span<const int> items{m_ptr.get(), m_size};
   std::ostringstream output;
   output << "{";

   // insert each item in the dynamic array into the ostringstream
   for (size_t count{0}; const auto & item : items) {
      ++count;
      output << item << (count < m_size ? ", " : "");
   }

   output << "}";
   return output.str();
}

// determine if two MyArrays are equal and return true, otherwise
//  return false (**C++20 autogenerates != from this**)
bool MyArray::operator==(const MyArray& right) const noexcept {
   // compare corresponding elements of both MyArrays
   const std::span<const int> lhs{m_ptr.get(), size()};
   const std::span<const int> rhs{right.m_ptr.get(), right.size()};
   return std::equal(std::begin(lhs), std::end(lhs),
      std::begin(rhs), std::end(rhs));
}

// overloaded subscript operator for non-const MyArrays;
// reference return creates a modifiable lvalue
int& MyArray::operator[](size_t index) {
   // check for index out-of-range error
   if (index >= m_size) {
      throw std::out_of_range{"Index out of range"};
   }

   return m_ptr[index]; // reference return
}

// overloaded subscript operator for const MyArrays
// const reference return creates a non-modifiable lvalue
const int& MyArray::operator[](size_t index) const {
   // check for subscript out-of-range error
   if (index >= m_size) {
      throw std::out_of_range{"Index out of range"};
   }

   return m_ptr[index]; // returns copy of this element
}

// swap function used to implement copy-and-swap copy assignment operator
void swap(MyArray& a, MyArray& b) noexcept {
   std::swap(a.m_size, b.m_size); // swap using std::swap
   a.m_ptr.swap(b.m_ptr); // swap using unique_ptr swap member function
}

// overloaded output operator for class MyArray 
std::ostream& operator<<(std::ostream& out, const MyArray& a) {
   out << a.toString();
   return out; // enables std::cout << x << y;
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
