//---------------------------------------------------------------------------
// display.h
// Derived transaction class for display a patrons history
//---------------------------------------------------------------------------
// display class Implementation and assumptions:  
//   -- Assumed Patron exist and is in system.
//   -- Display is not included in the patrons history
//---------------------------------------------------------------------------
#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "transaction.h"

class Library;
class Display : public Transaction
{
public:
    //-------------------------------------------------------------------
    // Default Constructor
    Display();

    //-------------------------------------------------------------------
    // Destructor
    ~Display();

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
