#include "bookfactory.h"
//---------------------------------------------------------------------------
// bookfactory.cpp
// Derived class of Factory class for returning book objects
//---------------------------------------------------------------------------
// Bookfactory class Implementation and assumptions:  
//   -- Item* createObject(char) function returns new Book object, where the
//      type of book is determined by input char ('C' for ChildrensBook,
//      'F' for Fiction, 'P' for periodical).
//   -- objFactory data member is array of Item*, where each each index maps 
//      to a particular book type. 
//   -- Hashing function used to map a given char value to index of array
//   -- Invalid input chars return null pointers
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Default constructor
// Preconditions:   None
// Postconditions:  None
BookFactory::BookFactory()
{
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   Data points to memory on the heap
// Postconditions:  All data in objFactor is deallocated
BookFactory::~BookFactory()
{
   for (int i = 0; i < 26; i++) {
      delete objFactory[i]; 
      objFactory[i] = nullptr; 
   }
}

//---------------------------------------------------------------------------
// createObject 
// Preconditions:   char is valid char 
// Postconditions: returns object corresponding to char 
Item* BookFactory::createObject(char ch) const
{
   switch (ch) {
      case 'F':
         return new Fiction();
      case 'P':
         return new Periodical();
      case 'C':
         return new Children();
      default:
         return nullptr;
	 }
}