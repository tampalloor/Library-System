#include "patronhashmap.h"
//---------------------------------------------------------------------------
// patronhashmap.cpp
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

//--------------------------------------------------------------------------
//default destructor
//intializes variables
PatronHashMap::PatronHashMap()
{
   for (int i = 0; i < 10000; i++) { 
      patronArray[i].setFirstName(" ");
   }
}

//--------------------------------------------------------------------------
//destructor
//deallocates memory 
PatronHashMap::~PatronHashMap()
{
   //delete[] patronArray; 
   //patronArray = nullptr; 
}

//--------------------------------------------------------------------------
//insert
//inserts patron into hashmap, checks if patron ID is valid 
void PatronHashMap::insert(Patron* newPatron)
{
   if (this->patronArray[newPatron->getID()].getFirstName() == " ") {
      this->patronArray[newPatron->getID()] = *newPatron; 
   }
   else {
      cout << "ERROR: Patron ID  " << newPatron->getID() << " already exists. " << endl;
   }
}

//--------------------------------------------------------------------------
//retrieve 
//returns true if the patron exists
bool PatronHashMap::retrieve(int id, Patron*& assign)
{
   if (this->patronArray[id].getFirstName() != " ") {
      assign = &patronArray[id]; 
      return true; 
   }
   return false;
}

//--------------------------------------------------------------------------
//makeEmpty  
//None
void PatronHashMap::makeEmpty()
{
}

//--------------------------------------------------------------------------
//print  
//Used for the display history 
void PatronHashMap::print()
{
   for (int i = 0; i < 10000; i++) {
      if (this->patronArray[i].getFirstName() != " ") {
         cout << i << " " << patronArray[i].getFirstName() << " " << patronArray[i].getLastName() << endl; 
      }
   }
}

//--------------------------------------------------------------------------
//hash  
//None
int PatronHashMap::hash(int) const
{
   return 0;
}
