#include "item.h"
//---------------------------------------------------------------------------
// item.cpp
// Parent class for all items available for use/checkout in 
// the library
//---------------------------------------------------------------------------
// Item class:  
//   includes additional features:
//   -- (Virtual) Getters/Setters for all data members
//   -- Overloaded output operator for use with virtual print method
//
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
//   -- Item class not intended to be called directly other than as a pointer
//      to a derived class.
//   -- data members include itemFormat (e.g. 'H' for hardcopy), title,
//      and number of copies in stock
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default coonstructor 
//initializes variables 
Item::Item()
{
   copies = 5; 
}

//--------------------------------------------------------------------------
//destructor
//None
Item::~Item()
{
}

//--------------------------------------------------------------------------
//getTitle
//returns title of item 
string Item::getTitle() const
{
   return title;
}

//--------------------------------------------------------------------------
//inStock 
//returns true if the number of copies is >  0 
bool Item::inStock() const
{
   if (copies > 0) {
      return true; 
   }
   return false;
}

//--------------------------------------------------------------------------
//operator <<  
//None
ostream& operator<<(ostream& stream, const Item&)
{
   return stream; 
}

//--------------------------------------------------------------------------
//print
//None
void Item::print() const
{
}

//--------------------------------------------------------------------------
//getNumCopies 
//returns current number of copies for item
int Item::getNumCopies() const
{
   return copies;
}

//--------------------------------------------------------------------------
//setNumCopies  
//sets current copies for item 
void Item::setNumCopies(int copy)
{
   copies = copy; 
}
