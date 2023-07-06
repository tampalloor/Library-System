//---------------------------------------------------------------------------
// bookfactory.h
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
#ifndef BOOKFACTORY
#define BOOKFACTORY

#include "fiction.h"
#include "children.h"
#include "periodical.h"
#include "item.h"

class BookFactory
{
public:
//---------------------------------------------------------------------------
// Default constructor
// Preconditions:   None
// Postconditions:  None
    BookFactory();

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   Data points to memory on the heap
// Postconditions:  All data in objFactor is deallocated
    virtual ~BookFactory();

//---------------------------------------------------------------------------
// createObject 
// Preconditions:   char is valid char 
// Postconditions: returns object corresponding to char 
    Item* createObject(char ch) const;
protected:
    Item* objFactory[26];

};

#endif
