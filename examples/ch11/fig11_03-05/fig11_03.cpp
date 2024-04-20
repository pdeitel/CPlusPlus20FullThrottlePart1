// fig11_03.cpp
// MyArray class -- heavily cut down from full example.
// https://learning.oreilly.com/videos/c-20-fundamentals/9780136875185/9780136875185-CP20_Lesson11_09/ 
#include <algorithm>
#include <format>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <span>
#include <stdexcept>
#include <string>
#include <utility> // for std::move

class MyArray final {
   // swap function used to implement copy-and-swap copy assignment operator
   friend void swap(MyArray& a, MyArray& b) noexcept {
      std::swap(a.m_size, b.m_size); // swap using std::swap
      a.m_ptr.swap(b.m_ptr); // swap using unique_ptr swap member function
   }

public:
   // construct a MyArray with a braced-initializer list of ints
   explicit MyArray(std::initializer_list<int> list)
      : m_size{list.size()}, m_ptr{std::make_unique<int[]>(list.size())} {

      // copy list argument's elements into m_ptr's underlying int array 
      // m_ptr.get() returns the int array's starting memory location
      std::copy(std::begin(list), std::end(list), m_ptr.get());
      std::cout << std::format(
         "MyArray(initializer_list) ctor: {}\n", toString());
   }

   // copy constructor: must receive a reference to a MyArray
   MyArray(const MyArray& original)
      : m_size{original.size()},
      m_ptr{std::make_unique<int[]>(original.size())} {

      // copy original's elements into m_ptr's underlying int array 
      const std::span<const int> source{
         original.m_ptr.get(), original.size()};
      std::copy(std::begin(source), std::end(source), m_ptr.get());
      std::cout << std::format("MyArray copy ctor: {}\n", toString());
   }

   // copy assignment operator: implemented with copy-and-swap idiom
   MyArray& operator=(const MyArray& right) {
      MyArray temp{right}; // invoke copy constructor
      swap(*this, temp); // exchange contents of this object and temp
      std::cout << std::format("MyArray copy assignment: {}\n", toString());
      return *this;
   }

   // move constructor: must receive an rvalue reference to a MyArray                      
   MyArray(MyArray&& original) noexcept
      : m_size{std::exchange(original.m_size, 0)},
      m_ptr{std::move(original.m_ptr)} {// move original.m_ptr into m_ptr
      std::cout << std::format("MyArray move ctor: {}\n", toString());
   }

   // move assignment operator
   MyArray& operator=(MyArray&& right) noexcept {
      if (this != &right) {// avoid self-assignment  
         // move right's data into this MyArray
         m_size = std::exchange(right.m_size, 0); // indicate right is empty
         m_ptr = std::move(right.m_ptr);
      }

      std::cout << std::format("MyArray move assignment: {}\n", toString());
      return *this; // enables x = y = z, for example                    
   }

   // destructor
   ~MyArray() {
      std::cout << std::format("MyArray destructor: \n", toString());
   }

   size_t size() const noexcept {return m_size;} // return size

   // build and return a string representation of a MyArray
   std::string toString() const {
      const std::span<const int> items{m_ptr.get(), m_size};
      std::string s;

      for (const auto & item : items) {
         s += std::to_string(item) + " ";
      }

      return s;
   }

   // determine if two MyArrays are equal and return true, otherwise
   // return false (**C++20 autogenerates != from this**)
   bool operator==(const MyArray& right) const noexcept {
      // compare corresponding elements of both MyArrays
      const std::span<const int> lhs{m_ptr.get(), size()};
      const std::span<const int> rhs{right.m_ptr.get(), right.size()};
      return std::equal(std::begin(lhs), std::end(lhs),
         std::begin(rhs), std::end(rhs));
   }

private:
   size_t m_size{0}; // pointer-based array size
   std::unique_ptr<int[]> m_ptr; // smart pointer to integer array
};

// overloaded operator<< is not a friend--does not access private data
std::ostream& operator<<(std::ostream& out, const MyArray& a) {
   out << a.toString();
   return out; // enables std::cout << x << y;
}

int main() {
   MyArray ints1{1, 2, 3}; 
   MyArray ints2{4, 5, 6, 7, 8}; 
 
   // print ints1 size and contents
   std::cout << std::format("\nints1 size: {}\ncontents: ", ints1.size())
      << ints1; // uses overloaded <<

   // print ints2 size and contents
   std::cout << std::format("\nints2 size: {}\ncontents: ", ints2.size())
      << ints2; // uses overloaded <<

   // use overloaded inequality (!=) operator 
   std::cout << std::format("\n\nints1 != ints2: {}\n", ints1 != ints2);

   // create MyArray ints3 by copying ints1      
   MyArray ints3{ints1}; // invokes copy constructor

   // print ints3 size and contents                
   std::cout << std::format("\nints3 size: {}\ncontents: ", ints3.size())
      << ints3;

   // copy assignment (=) operator
   std::cout << "\n\nAssigning ints2 to ints1:\n";
   ints1 = ints2; // note ints1 is smaller

   std::cout << "ints1: " << ints1 << "\nints2: " << ints2;

   // use overloaded equality (==) operator 
   std::cout << std::format("\n\nints1 == ints2: {}\n", ints1 == ints2);

   // convert ints4 to an rvalue reference with std::move and
   // use the result to initialize MyArray ints4
   std::cout << "\nInitialize ints4 with result of std::move(ints3)\n";
   MyArray ints4{std::move(ints3)}; // invokes move constructor

   std::cout << std::format("\nints4 size: {}\ncontents: ", ints4.size())
      << ints4
      << std::format("\nSize of ints3 is now : {}", ints3.size());

   // move contents of ints4 into ints3
   std::cout << "\n\nMove ints4 into ints3 via move assignment\n";
   ints3 = std::move(ints4); // invokes move assignment

   std::cout << std::format("\nints3 size: {}\ncontents: ", ints3.size())
      << ints3
      << std::format("\nSize of ints4 is now: {}", ints4.size());
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
