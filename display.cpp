#include "display.h"
//---------------------------------------------------------------------------
// display.h
// Derived transaction class for display a patrons history
//---------------------------------------------------------------------------
// display class Implementation and assumptions:  
//   -- Assumed Patron exist and is in system.
//   -- Display is not included in the patrons history
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default destructor
//intializes variables
Display::Display()
{
   book = nullptr;
   inTree = false;
   transactionType = 'H';
}

//--------------------------------------------------------------------------
//destructor
//None
Display::~Display()
{
}


//--------------------------------------------------------------------------
//create
//None
Transaction* Display::create() const
{
   return nullptr;
}

//--------------------------------------------------------------------------
//setData
//None - Does nothign since it is not included in the history 
bool Display::setData(istream&)
{
   return true;
}

//--------------------------------------------------------------------------
//print
//used for display history 
void Display::print() const
{

}

//--------------------------------------------------------------------------
//execute
//checksout the desired book and doees all the proper error checks 
bool Display::execute(Library* lib, BookInventory books[])
{
	 //Prints each book inventory 
   cout << "FICTION BOOKS" << endl;
   books['F' - 'A'].print('F');
   cout << endl << endl;

   cout << "CHILDREN BOOKS" << endl;
   books['C' - 'A'].print('C');
   cout << endl << endl;

   cout << "PERIODICAL BOOKS" << endl;
   books['P' - 'A'].print('P');
   cout << endl << endl;
   return true; 
}
