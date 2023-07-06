#include "transaction.h"
//---------------------------------------------------------------------------
// transaction.cpp
// Parent transaction class for main transaction types: checkout, return, 
// and display history
//---------------------------------------------------------------------------
// Transaction class Implementation and assumptions:  
//   -- Transaction class not intended to be called directly other than as
//      a pointer to derived classes.
//   -- Data members include pointer to Item object upon which it is acting, 
//      pointer to patron who is taking part in transaction, a bool type for 
//      confirming whether book data member is in library, and char for 
//      transaction type ('C' for checkout, 'R' for return, 'H' for 
//      displaying history)
//   -- Transaction* create to be implemented in derived classes, returns 
//      pointer to transaction object.
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default destructor
//None
Transaction::Transaction()
{
   book = nullptr; 
   inTree = false; 
   transactionType = 'X';
}

//--------------------------------------------------------------------------
//destructor
//deallocates the transaction book
Transaction::~Transaction()
{
   delete book; 
   book = nullptr; 
}

//--------------------------------------------------------------------------
//getTransactionType 
//gets the transaction type corresponding to checkout, return or history 
char Transaction::getTransactionType() const
{
   return transactionType;
}

//--------------------------------------------------------------------------
//setTransactionType 
//sets the transaction type corresponding to checkout, return or history 
void Transaction::setTransactionType(char ch)
{
   transactionType = ch; 
}

//--------------------------------------------------------------------------
//print
//None
void Transaction::print() const
{
}

//--------------------------------------------------------------------------
//getPatron 
//returns the patron of the current transaction 
Patron Transaction::getPatron()
{
   return patron;
}

//--------------------------------------------------------------------------
//getItem 
//returns the iteem of the current transaction 
Item* Transaction::getItem()
{
   return book;
}

//--------------------------------------------------------------------------
//setItem 
//returns the iteem of the current transaction 
bool Transaction::setItem(Item* theItem)
{
   book = theItem;
   return true; 
}



