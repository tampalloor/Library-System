//---------------------------------------------------------------------------
// return.h
// Derived transaction class for returning a checked out book
//---------------------------------------------------------------------------
// Return class Implementation and assumptions:  
//   -- Assumes Patron and Book both exist and are in system. 
//   -- Checks to make sure book is in Patron's list of currently
//      checked out books
//   -- Transaction* create returns ReturnBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef RETURN_H_
#define RETURN_H_
#include "transaction.h"
#include <limits>
class Library; 
class Return : public Transaction
{
public:
    //-------------------------------------------------------------------
    // Default Constructor
    Return();

    //-------------------------------------------------------------------
    // Destructor
    ~Return();

    //-------------------------------------------------------------------
    // For use with transactionfactory class - creates and returns an 
    // instance of the ReturnBook class
    virtual Transaction* create() const;

    virtual bool setData(istream&);


    //-------------------------------------------------------------------
    // Virtual print method for use with output overload
    virtual void print() const;

    //-------------------------------------------------------------------
    // Virtual function to perform the transaction
    virtual bool execute(Library* lib, BookInventory books[]);
};

#endif
