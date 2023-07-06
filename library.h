//--------------------------------------------------------------------------
// library.h
// Primary manager class to be called by the main. Handles building of the
// library, creating list of patrons, and processing transactions.
//--------------------------------------------------------------------------
// Library class Implementation and assumptions:  
//   -- Data members include the hashmap of patrons, hash table of binary 
//      trees holding all books, book and transaction factory objects for
//      instantiating book and transaction objects.
//   -- Hash function maps char of book type (C for childrens book, F for
//      fiction, and P for Periodical) to indexes in the array of Binary 
//      Trees. Assumes 1:1 mapping (closed hashing), no collision handling
//
//--------------------------------------------------------------------------
#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "patronhashmap.h"
#include "bookinventory.h"
#include "bookfactory.h"
#include "transactionfactory.h"
#include <iomanip>
#include <limits>
class Library
{
public:

    //--------------------------------------------------------------------------
    //Default constructor 
    //None
    Library();
        
    //--------------------------------------------------------------------------
    //Destructor
    //None
    ~Library();

    //--------------------------------------------------------------------------
    //processTransactions
    //reads in the file and uses polymorphism to assign variables
    void processTransactions(ifstream&); // processes all transactions


    void addBooks(ifstream&); // adds all books to the library
    //--------------------------------------------------------------------------
    //addPatrons
    //reads in the file and uses polymorphism to assign variables
    void addPatrons(ifstream&); // adds all patrons to library system

    //--------------------------------------------------------------------------
    //print
    //None
    void print(char) const; // prints out entire library

    //--------------------------------------------------------------------------
    //getMap
    //returns patronhashmap
    PatronHashMap getMap() const;

private:
    PatronHashMap patrons;//store patrons
    BookInventory books[26]; //store genres
    BookFactory bookFactory;//create book objects
    TransactionFactory transactionFactory; //create transaction objects
    int hash(char) const;
};
#endif 
