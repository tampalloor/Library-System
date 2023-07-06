//---------------------------------------------------------------------------
// displayhistory.h
// Derived transaction class for displaying a patron's history
//---------------------------------------------------------------------------
// DisplayHistory class Implementation and assumptions:  
//   -- Assumed Patron exists and is in the system.
//   -- Item* data member set to nullptr.
//   -- Transaction* create returns DisplayHistory object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef DISPLAYHISTORY_H_
#define DISPLAYHISTORY_H_
#include "transaction.h"
class Library; 
class DisplayHistory : public Transaction
{
public:
    //-------------------------------------------------------------------
    // Default Constructor
    DisplayHistory();

    //-------------------------------------------------------------------
    // Destructor
    ~DisplayHistory();

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
