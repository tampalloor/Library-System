//---------------------------------------------------------------------------
// patron.h
// Class representing a patron registered with the library
//---------------------------------------------------------------------------
// Patron class:
//
// Implementation and assumptions:
// -- Maintains history of transactions and list of borrowed books
// -- Performs methods to history such as adding and printing a 
// Patron's history, transactions and also adding and removing book items 
// from the borrowed list. 
// -- Assumes Item class and its derived classes have been properly 
// implemented
// 
//---------------------------------------------------------------------------

#ifndef PATRON_H_
#define PATRON_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class TransactionFactory;
class Transaction;
class Item; 
class Patron
{
    friend ostream& operator<<(ostream&, const Patron&);
public:
    //-------------------------------------------------------------------
    // Default Constructor
    Patron();

    Patron(string, string, int);
    //-------------------------------------------------------------------
    // Destructor
    ~Patron();

    //-------------------------------------------------------------------
    // Getters/Setters
    string getFirstName() const;
    string getLastName() const;
    int getID() const;

    void setFirstName(string);
    void setLastName(string);
    bool setID(int);

    void setData(istream& file);

    //-------------------------------------------------------------------
    // Prints out user's entire history
    void printHistory();

    //-------------------------------------------------------------------
    // adds a transaction to user's history
    void addToHistory(Item*, char);

    //-------------------------------------------------------------------
    // adds a book to user's list of borrowed books
    void addToBorrowList(Item*);

    //-------------------------------------------------------------------
    // Removes a book from user's list of borrowed books
    void removeFromBorrowList(Item*);

    //-------------------------------------------------------------------
    // Checks to see if given book is in patron's list of currently 
    // borrow books
    bool inCurrentBooks(const Item&);

    //-------------------------------------------------------------------
    // prints out user's borrowed book list
    void printBorrowList();

private:
    string first;
    string last;
    int patronID;
    vector<Transaction*> transactions; 
    vector<Item*> borrowlist; 
    TransactionFactory* transFactory; 
};
#endif
