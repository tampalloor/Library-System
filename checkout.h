//---------------------------------------------------------------------------
// checkout.h
// Derived transaction class for checking out a book
//---------------------------------------------------------------------------
// Checkout class Implementation and assumptions:  
//   -- Assumed Patron and Book both exist and are in system.
//   -- Transaction* create returns BorrowBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef CHECKOUT_H_
#define CHECKOUT_H_
#include "transaction.h"
#include <limits>
class Library;
class Checkout : public Transaction
{
public:
    //-------------------------------------------------------------------
    // Default Constructor
    Checkout();

    //-------------------------------------------------------------------
    // Destructor
    ~Checkout();

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
