#include "checkout.h"
#include "library.h"
#include "item.h"
#include "patron.h"
#include "bookinventory.h"
//---------------------------------------------------------------------------
// checkout.cpp
// Derived transaction class for checking out a book
//---------------------------------------------------------------------------
// Checkout class Implementation and assumptions:  
//   -- Assumed Patron and Book both exist and are in system.
//   -- Transaction* create returns BorrowBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default destructor
//intializes variables
Checkout::Checkout()
{
   book = nullptr;
   inTree = false;
   transactionType = 'C'; 
}

//--------------------------------------------------------------------------
//destructor
//None
Checkout::~Checkout()
{
}

//--------------------------------------------------------------------------
//create
//None
Transaction* Checkout::create() const
{
   return nullptr;
}

//--------------------------------------------------------------------------
//setData
//reads in the file and sets transaction variables accordingly 
bool Checkout::setData(istream& file)
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
void Checkout::print() const
{
   cout << "Checkout "; 
   book->print();
}


//--------------------------------------------------------------------------
//execute
//checksout the desired book and doees all the proper error checks 
bool Checkout::execute(Library* lib, BookInventory books[])
{
   Patron* thePatron;
   Patron patron = this->getPatron();
    //checks if the patron exists 
   if (lib->getMap().retrieve(patron.getID(), thePatron)) {
      Item* patronBook = this->getItem();
      Item* theBook;
        //Checks if the book exists 
      if (books[patronBook->getFormat() - 'A'].retrieve(*patronBook, 
           theBook)) {
            //Checks if their are enough copies 
         if (theBook->getNumCopies() > 0) {
                //Decreases number of copies 
            int copies = theBook->getNumCopies(); 
            theBook->setNumCopies(copies - 1); 
                //Adds transaction to history 
            thePatron->addToHistory(theBook, 'C');
                //Adds book to borrow list 
            thePatron->addToBorrowList(theBook);
            return true;
         }
            //Error handling 
         else {
            cout << "ERROR: Not enough copies for " 
                 << patronBook->getTitle() << " by " 
                 << patronBook->getLastName() << " "
                 << patronBook->getFirstName() << endl;
            return false; 
         }
      }
      else {
         cout << "ERROR: " << patronBook->getTitle()
              << " by " << patronBook->getLastName() 
              << " " << patronBook->getFirstName() 
              << " does not exist." << endl;
         return false; 
      }
   }
   else {
      cout << "ERROR: Patron ID " << patron.getID() << " does not exist."
           << endl;
      return false;
   }
}