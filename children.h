//---------------------------------------------------------------------------
// childrens.h
// Derived class of Book class for book type of Children's Book
//---------------------------------------------------------------------------
// Childrens class Implementation and assumptions:  
//   -- Item* create() function returns new ChildrensBook object for use
//      in factory class
//   -- setData function sets all data members for Children's book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of ChildrensBook 
//      class: sorted by title, then author. No other data used for sorting, 
//      and criteria uniquely identifies each childrens book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//
//---------------------------------------------------------------------------
#ifndef CHILDRENS_H_
#define CHILDRENS_H_
#include "book.h"

class Children : public Book
{
public:
    //-------------------------------------------------------------------
    // Default Constructor
    Children();

    //-------------------------------------------------------------------
    // Destructor
    virtual ~Children();

    //-------------------------------------------------------------------
    // Getters/Setters
    virtual int getYear() const;
    virtual char getFormat() const;
    virtual char getType() const;

    virtual void setYear(int);
    virtual void setFormat(char);


    virtual string getFirstName() const;
    virtual string getLastName() const;

    virtual void setFirstName(string);
    virtual void setLastName(string);
    virtual int getMonth() const;

    //-------------------------------------------------------------------
    // For use with bookfactory class - creates and returns
    // an instance of the ChildrensBook class 
    virtual Item* create() const;

    //-------------------------------------------------------------------
    // sets book data from book data file
    virtual bool setData(istream&);

    //-------------------------------------------------------------------
    // sets item data from transaction data file
    virtual bool setTransactionData(istream&);

    //-------------------------------------------------------------------
    // Virtual print function for use with output overload
    virtual void print() const;

    //-------------------------------------------------------------------
    // Operator overloads
    virtual bool operator==(const Item&) const;
    virtual bool operator!=(const Item&) const;
    virtual bool operator<(const Item&) const;
    virtual bool operator>(const Item&) const;

protected:
    // author name
    string name;
    string first; 
    string last; 
};

#endif
