#include "patron.h"
#include "transaction.h"
#include "item.h"
#include "children.h"
#include "fiction.h"
#include "periodical.h"
#include "transactionfactory.h"
//---------------------------------------------------------------------------
// patron.h
// Class representing a patron registered with the library
//---------------------------------------------------------------------------
// Patron class:
//
// Implementation and assumptions:
// -- Maintains history of transactions and list of borrowed books
// -- Performs methods to history such as adding and printing a 
// Patron's history, transactions and also adding and removing book items 
// from the borrowed list. 
// -- Assumes Item class and its derived classes have been properly 
// implemented
// 
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default constructor 
//intializes variables
Patron::Patron()
{
   patronID = -1; 
   first = " ";
   last = " ";
}

//--------------------------------------------------------------------------
//constructor
//intializes variables
Patron::Patron(string theFirst, string theLast, int id)
{
   first = theFirst; 
   last = theLast; 
   patronID = id; 
}

//--------------------------------------------------------------------------
//destructor
//deallocates borrowlist, transactions and transFactory
Patron::~Patron()
{
    /*for (int i = 0; i < transactions.size(); i++) {
        delete transactions.at(i);
        transactions.at(i) = nullptr; 
    }
    delete transFactory;
    transFactory = nullptr; 

    for (int i = 0; i < borrowlist.size(); i++) {
        delete borrowlist.at(i);
        borrowlist.at(i) = nullptr;
    }*/
}

//--------------------------------------------------------------------------
//getFirstName 
//gets the first name of the patron 
string Patron::getFirstName() const
{
   return first;
}

//--------------------------------------------------------------------------
//getLastName  
//gets the last name of the patron 
string Patron::getLastName() const
{
   return last;
}

//--------------------------------------------------------------------------
//getID 
//gets the ID name of the patron 
int Patron::getID() const
{
   return patronID;
}

//--------------------------------------------------------------------------
//setFirstName  
//sets the first name of the patron 
void Patron::setFirstName(string name)
{
   first = name;
}

//--------------------------------------------------------------------------
//setLastName  
//sets the last name of the patron 
void Patron::setLastName(string name)
{
   last = name; 
}

//--------------------------------------------------------------------------
//setID 
//sets the ID name of the patron 
bool Patron::setID(int id)
{
   if (id > 999 || id < 10000) {
      patronID = id;
      return true; 
   }
   else {
      cout << "ERROR: Invalid Patron id " << id << endl;
      return false; 
   }
}


//--------------------------------------------------------------------------
//setData
//reads in the file and sets transaction variables accordingly 
void Patron::setData(istream& file)
{
   string name;
   file >> name;
   this->first = name;
   file.get();

   file >> name;
   this->last = name;
}


//--------------------------------------------------------------------------
//printHistory
//used for display history of transactions 
void Patron::printHistory()
{
    for (int i = 0; i < transactions.size(); i++) {
       transactions.at(i)->print(); 
       cout << endl;
    }
}


//--------------------------------------------------------------------------
//addToHistory
//adds the patrons transactions to the vector 
void Patron::addToHistory(Item* newItem, char trans)
{
   //creates respective object using the char 
   Transaction* transaction = transFactory->createObject(trans);
   (*transaction).setTransactionType(trans); 
   transaction->setTransactionType(trans); 
   transaction->setItem(newItem);

   transactions.push_back(transaction);
}


//--------------------------------------------------------------------------
//addToBorrowList
//adds the item to the patrons current books 
void Patron::addToBorrowList(Item* addedItem)
{
   borrowlist.push_back(addedItem);
}

//--------------------------------------------------------------------------
//removeBorrowList
//removes the item to the patrons current books 
void Patron::removeFromBorrowList(Item* removedItem)
{ 
   for (int i = 0; i < borrowlist.size(); i++) {
      if (borrowlist.at(i) == removedItem) {
         borrowlist.erase(borrowlist.begin() + i); 
         break; 
      }
   }
}

//--------------------------------------------------------------------------
//inCurrentBooks
//returns true if the item is in the patrons current books 
bool Patron::inCurrentBooks(const Item& theItem)
{
   for (int i = 0; i < borrowlist.size(); i++) {
      if (*borrowlist.at(i) == theItem) {
         return true; 
      }
   }
   return false;
}

//--------------------------------------------------------------------------
//printBorrowlist
//used for testing purposes, None
void Patron::printBorrowList()
{
}

//--------------------------------------------------------------------------
//operator << 
//None 
ostream& operator<<(ostream& stream, const Patron&)
{
   return stream; 
}
