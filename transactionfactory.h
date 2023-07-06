// Derived class of Factory class for returning transaction objects
//---------------------------------------------------------------------------
// Transactionfactory class Implementation and assumptions:  
//   -- Item* createObject(char) function returns new Transaction object, 
//      where the type of transaction is determined by input char 
//      ('C' for checkout, 'R' for return, 'H' for displaying a patron's
//      history).
//   -- objFactory data member is array of Transaction*, where each each 
//      index maps to a particular transaction type. 
//   -- Hashing function used to map a given char value to index of array
//   -- Invalid input chars return null pointers
//
//---------------------------------------------------------------------------
#ifndef TRANSACTIONFACTORY
#define TRANSACTIONFACTORY

#include "transaction.h"
#include "checkout.h"
#include "return.h"
#include "display.h"
#include "displayhistory.h"

class Transaction; 

class TransactionFactory
{
public:
    //--------------------------------------------------------------------------
    //default destructor
    //intializes objFactory 
    TransactionFactory();

    //--------------------------------------------------------------------------
    //destructor
    //deallocates objFactory 
    virtual ~TransactionFactory();

    //--------------------------------------------------------------------------
    //createObject
    //Creates the necassary transaction objects
    Transaction* createObject(char ch) const;
protected:
    Transaction* objFactory[26];

};

#endif
