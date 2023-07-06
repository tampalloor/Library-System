//---------------------------------------------------------------------------
// patronhashmap.h
// Hash table to store all patrons. 
//---------------------------------------------------------------------------
// PatronHashMap class Implementation and assumptions:  
//   -- Hash function computes index of array based on patron's id
//   -- Open hashing, collisions handled via linked lists stored in each slot
//      of array rather than the patrons themselves. 
//   -- Memory allocated dynamically as more patrons are added to the hash 
//      table.
//   -- Assumes patron's ids are determined randomly to maintain fast lookup 
//      ~O(1) time.
//
//---------------------------------------------------------------------------
#ifndef PATRON_HASHMAP
#define PATRON_HASHMAP

#include <iostream>
#include "patron.h"
using namespace std;

const int TABLE_SIZE = 101; // number of slots in hash table
class PatronHashMap
{
public:
    //-------------------------------------------------------------------
    // Default Constructor
    PatronHashMap();

    //-------------------------------------------------------------------
    // Destructor
    ~PatronHashMap();

    //-------------------------------------------------------------------
    // Insert patron into hash map
    void insert(Patron*);

    //-------------------------------------------------------------------
    // Find patron in hash map
    bool retrieve(int, Patron*&);

    void makeEmpty();
    //-------------------------------------------------------------------
    // Print out all patrons contained in the hashmap
    void print();

private:
    Patron* patronArray = new Patron[10000];
    //-------------------------------------------------------------------
    // Hash function
    int hash(int) const;
};

#endif
