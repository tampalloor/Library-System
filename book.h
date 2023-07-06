//---------------------------------------------------------------------------
// book.h
// Derived class of Item, Parent class for all books contained in the library
//---------------------------------------------------------------------------
// Book class:  
//   -- (Virtual) Getters/Setters for all data members and pure virtual
//      getters/setters for use in derived classes
//
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
//   -- Book class not intended to be called directly other than as a pointer
//      to a derived class.
//   -- Addition of publication year (int) and booktype (char) as data members
//---------------------------------------------------------------------------
#ifndef BOOK
#define BOOK

#include "item.h"

class Book : public Item
{
public:
    //-------------------------------------------------------------------
    // Default Constructor
    Book();

    //-------------------------------------------------------------------
    // Destructor
    virtual ~Book();

    //-------------------------------------------------------------------
    // Getters/Setters
    virtual int getYear() const;
    virtual char getFormat() const;
    virtual char getType() const;

    virtual void setYear(int);
    virtual void setFormat(char);
    virtual void setTitle(string); 

    virtual string getLastName() const = 0;     //Pure virtual
    virtual string getFirstName() const = 0;    //Pure virtual
    virtual int getMonth() const = 0;           //Pure virtual

    //-------------------------------------------------------------------
    // For use with bookfactory class (pure virtual)
    virtual Item* create() const = 0;

    //-------------------------------------------------------------------
    // sets book data from data file (pure virtual)
    virtual bool setData(istream&) = 0;

    //-------------------------------------------------------------------
    // sets item data from transaction data file (pure virtual)
    virtual bool setTransactionData(istream&) = 0;

    //-------------------------------------------------------------------
    // Virtual print function for use with output overload
    virtual void print() const;

    //-------------------------------------------------------------------
    // Operator overloads (pure virtual)
    virtual bool operator==(const Item&) const = 0;
    virtual bool operator!=(const Item&) const = 0;
    virtual bool operator<(const Item&) const = 0;
    virtual bool operator>(const Item&) const = 0;

protected:
    // further data members for book items
    int year;
    char bookType;
};

#endif
