#include "displayhistory.h"
#include "library.h"
#include "item.h"
#include "patron.h"
#include "bookinventory.h"
//---------------------------------------------------------------------------
// displayhistory.cpp
// Derived transaction class for displaying a patron's history
//---------------------------------------------------------------------------
// DisplayHistory class Implementation and assumptions:  
//   -- Assumed Patron exists and is in the system.
//   -- Item* data member set to nullptr.
//   -- Transaction* create returns DisplayHistory object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Default constructor 
//Initializes values 
DisplayHistory::DisplayHistory()
{
   book = nullptr;
   inTree = false;
   transactionType = 'D';
}

//---------------------------------------------------------------------------
//Destructor
//None
DisplayHistory::~DisplayHistory()
{
}


//---------------------------------------------------------------------------
//create
//None
Transaction* DisplayHistory::create() const
{
   return nullptr;
}

//---------------------------------------------------------------------------
//setData
//Reads file and sets data accordingly 
bool DisplayHistory::setData(istream& file)
{
   file.get(); 
   int patronID;
   file >> patronID;
    //Checks if ID is 4 digits 
   if (patronID < 1000 || patronID > 9999) {
      cout << "ERROR: patron ID " << patronID << " does not exist " 
           << endl;
      return false; 
   }
   this->patron.setID(patronID); 
   return true; 
}

//---------------------------------------------------------------------------
//print
//None
void DisplayHistory::print() const
{
}

//---------------------------------------------------------------------------
//execute 
//Prints the history for the desired patron 
bool DisplayHistory::execute(Library* lib, BookInventory books[])
{
   Patron* thePatron; 
   Patron patron = this->getPatron(); 
    //Checks if patron exists 
   if (lib->getMap().retrieve(patron.getID(), thePatron)) {
      cout << endl;
      cout << thePatron->getID() << " " << thePatron->getLastName() 
           << ", " << thePatron->getFirstName() << ":" << endl;
        //Prints transacion history 
      thePatron->printHistory(); 
      cout << endl << endl;
      return true; 
   }
   else {
      cout << "ERROR: patron ID " << patron.getID() << " does not exist. " 
           << endl;
      return false; 
   }
}
