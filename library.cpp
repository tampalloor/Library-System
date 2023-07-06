#include "library.h"
//--------------------------------------------------------------------------
// library.cpp
// Primary manager class to be called by the main. Handles building of the
// library, creating list of patrons, and processing transactions.
//--------------------------------------------------------------------------
// Library class Implementation and assumptions:  
//   -- Data members include the hashmap of patrons, hash table of binary 
//      trees holding all books, book and transaction factory objects for
//      instantiating book and transaction objects.
//   -- Hash function maps char of book type (C for childrens book, F for
//      fiction, and P for Periodical) to indexes in the array of Binary 
//      Trees. Assumes 1:1 mapping (closed hashing), no collision handling
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//Default constructor 
//None
Library::Library()
{
}

//--------------------------------------------------------------------------
//Destructor
//None
Library::~Library()
{
}

//--------------------------------------------------------------------------
//processTransactions
//reads in the file and uses polymorphism to assign variables
void Library::processTransactions(ifstream& file)
{	 
   for (;;) {
      char code; 
      file >> code;
      if (file.eof()) {
         break;
      }
      //creates respective object using the code 
      Transaction* newTransaction = 
      transactionFactory.createObject(code); 
      if (newTransaction != nullptr) {
         bool success = newTransaction->setData(file);
         if (success) {
            if (!newTransaction->execute(this, books)) {
               delete newTransaction;
               newTransaction = nullptr; 
            }
         }
      }
      else{
         cout << "ERROR: invalid Transaction " << code << endl; 
         file.ignore(std::numeric_limits<std::streamsize>::max(),
					 '\n');
      }

      delete newTransaction;
      newTransaction = nullptr;
	}
}

//--------------------------------------------------------------------------
//addPatrons
//reads in the file and uses polymorphism to assign variables
void Library::addPatrons(ifstream& file)
{
   for (;;)
   {
      int patronID;
      file >> patronID;
      if (file.eof())
      {
         break;
      }
      Patron* newPatron = new Patron();

      if (!newPatron->setID(patronID))
      {
         delete newPatron;
         newPatron = nullptr;
         file.ignore(std::numeric_limits<std::streamsize>::max(),
					 '\n');
      }
      else
      {
         newPatron->setData(file);
         patrons.insert(newPatron);
      }
		  
      delete newPatron; 
      newPatron = nullptr;
   }
}

//--------------------------------------------------------------------------
//print
//None
void Library::print(char) const
{
}

//--------------------------------------------------------------------------
//getMap
//returns patronhashmap
PatronHashMap Library::getMap() const
{
   return patrons;
}

//--------------------------------------------------------------------------
//hash
//None
int Library::hash(char) const
{
   return 0;
}

//--------------------------------------------------------------------------
//addBooks
//reads in the file and uses polymorphism to assign variables
void Library::addBooks(ifstream& file)
{
   for (;;) {
      char code;
      file >> code;
      if (file.eof()) {
         break;
      }
      //creates respective object using the code 
      Item* newItem = bookFactory.createObject(code);
      if (newItem != nullptr) {
         newItem->setData(file);
         bool success = books[code - 'A'].insert(newItem);
      } 
      else {
         cout << "ERROR: '" << code << "' is not a valid book genre"
              << endl;
         string garbage; 
         getline(file, garbage);
      }
   }
}