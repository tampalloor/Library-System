//---------------------------------------------------------------------------
// accounthistory.h
// Derived list class for saving all of patron's history in linked list
//---------------------------------------------------------------------------
// AccountHistory class Implementation and assumptions:  
//   -- Used as data member in Patron class
//   -- Allows append only
//   -- Transaction type stored as char, book as Item*
//
//---------------------------------------------------------------------------
#ifndef ACCOUNT_HISTORY
#define ACCOUNT_HISTORY


#include <list>
class Item; 
class Transactions; 
class AccountHistory
{
public:
    //-------------------------------------------------------------------
    // Default constructor
    AccountHistory();

    //-------------------------------------------------------------------
    // Default constructor
    virtual ~AccountHistory();

    //-------------------------------------------------------------------
    // Virtual function to see if list is empty
    virtual bool isEmpty() const;

    //-------------------------------------------------------------------
    // Virtual function to add transaction to end of list
    virtual void append(Item*, char);

    //-------------------------------------------------------------------
    // Function to print out entire account history
    virtual void print() const;

    void makeEmpty();

private:
    //list<Transactions*> history; 
};

#endif
