#include "return.h"
#include "library.h"
#include "item.h"
#include "patron.h"
#include "bookinventory.h"
//---------------------------------------------------------------------------
// return.cpp
// Derived transaction class for returning a checked out book
//---------------------------------------------------------------------------
// Return class Implementation and assumptions:  
//   -- Assumes Patron and Book both exist and are in system. 
//   -- Checks to make sure book is in Patron's list of currently
//      checked out books
//   -- Transaction* create returns ReturnBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default destructor
//intializes variables
Return::Return()
{
   book = nullptr;
   inTree = false;
   transactionType = 'R';
}

//--------------------------------------------------------------------------
//destructor
//None
Return::~Return()
{
}

//--------------------------------------------------------------------------
//create
//None
Transaction* Return::create() const
{
   return nullptr;
}

//--------------------------------------------------------------------------
//setData
//reads in the file and sets transaction variables accordingly 
bool Return::setData(istream& file)
{
   file.get();

   int patronId;
   file >> patronId;

   //Checks if ID is 4 digits 
   if (patronId < 1000 || patronId >9999) {
      cout << "ERROR: invalid patron ID: " << patronId << endl;
      file.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n');
      return false;
   }

   patron.setID(patronId);

   file.get();
   char bookType;
   file >> bookType;
   if (bookType != 'C' && bookType != 'P' && bookType != 'F') {
      cout << "ERROR: Invalid book type " << bookType << endl;
      file.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n');
      return false;
   }

   //creates respective object using the type 
   book = makeBooks.createObject(bookType);

   file.get();
   char format;
   file >> format;
   if (format != 'H') {
      cout << "ERROR: Invlaid book format " << format << endl;
      file.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n');
      return false;
   }
   file.get();

   book->setTransactionData(file);
   return true;
}

//--------------------------------------------------------------------------
//print
//used for display history 
void Return::print() const
{
   cout << "Return ";
   book->print();
}


//--------------------------------------------------------------------------
//execute
//checksout the desired book and doees all the proper error checks 
bool Return::execute(Library* lib, BookInventory books[])
{
   Patron* thePatron;
   Patron patron = this->getPatron();
   //Checks if patron exists 
   if (lib->getMap().retrieve(patron.getID(), thePatron)) {
      Item* patronBook = this->getItem();
      Item* theBook;
      //Checks if the book exists 
      if (books[patronBook->getFormat() - 'A'].retrieve(*patronBook,
          theBook)) {
         //Checks if the patron already has the book
         if (thePatron->inCurrentBooks(*theBook)) {
            //increases number of copies 
            int copies = theBook->getNumCopies();
            theBook->setNumCopies(copies + 1);
            //adds to tranasction history 
            thePatron->addToHistory(theBook, 'R');
            //Takes the book out of the patrons current book
            thePatron->removeFromBorrowList(theBook);
            return true; 
         }
         //error handling 
         else {
            cout << "ERROR: The book " << patronBook->getTitle() 
                 << " by " << patronBook->getLastName() << " "
                 << patronBook->getFirstName() << 
                    " was never checked out by patron ID "
                 << thePatron->getID() << endl;
            return false; 
         }
      }
      else {
         cout << "ERROR: " << patronBook->getTitle() << " by " 
              << patronBook->getLastName() << " "
              << patronBook->getFirstName() << " does not exist." 
              << endl;
         return false; 
      }
   }
   else {
      cout << "ERROR: Patron ID " << patron.getID() << 
              " does not exist." << endl;
      return false; 
   }
}
