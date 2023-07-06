#include "fiction.h"
//---------------------------------------------------------------------------
// fiction.cpp
// Derived class of Book class for Fiction books
//---------------------------------------------------------------------------
// Fiction class Implementation and assumptions:  
//   -- Item* create() function returns new Fiction object for use
//      in factory class
//   -- setData function sets all data members for fiction book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of Fiction 
//      class: sorted by author, then title. No other data used for sorting, 
//      and criteria uniquely identifies each fiction book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default destructor
//None
Fiction::Fiction()
{
}

//--------------------------------------------------------------------------
//destructor
//None
Fiction::~Fiction()
{
}

//--------------------------------------------------------------------------
//getFirstName
//return first name of author 
string Fiction::getFirstName() const
{
   return first;
}

//--------------------------------------------------------------------------
//getlatName
//returns last name of author 
string Fiction::getLastName() const
{
   return last;
}

//--------------------------------------------------------------------------
//setFirstName
//sets the first name of the author 
void Fiction::setFirstName(string newName)
{
   first = newName; 
}

//--------------------------------------------------------------------------
//setLastName
//sets last name of author 
void Fiction::setLastName(string newName)
{
   last = newName; 
}

//--------------------------------------------------------------------------
//getMonth
//returns 0 since Fiction books have no month
int Fiction::getMonth() const
{
   return 0;
}

//--------------------------------------------------------------------------
//create
//None
Item* Fiction::create() const
{
   return nullptr;
}

//--------------------------------------------------------------------------
//setData
//reads in the file and sets fiction variables accordingly 
bool Fiction::setData(istream& file)
{
   this->bookType = 'F'; 
   itemFormat = bookType;

   file.get();

   string author;
   file >> author;
   this->last = author;
   file.get();
   string first; 
   getline(file, first, ',');
   this->first = first;

   file.get();
   string title;
   getline(file, title, ',');
   this->title = title; 

   file.get();
   int year;
   file >> year;
   this->year = year; 

   return true;
}

//--------------------------------------------------------------------------
//setTransactionData 
//reads in the file and sets transaction variables accordingly 
bool Fiction::setTransactionData(istream& file)
{
   string firstName;
   string lastName;
   string title;
   file >> lastName; 
   this->last = lastName;
   file.get();
   getline(file, firstName, ',');
   this->first = firstName;
   file.get();
   getline(file, title, ',');
   this->setTitle(title);
   this->setFormat('F');
   return true;
}

//--------------------------------------------------------------------------
//print
//used for display history 
void Fiction::print() const
{
   cout << " " << title << "   " << last << " " << first << "    " << year;
}
//--------------------------------------------------------------------------
//operator ==
//determines if two fiction books are equal using title, first and last name
bool Fiction::operator==(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Fiction& aFiction = static_cast<const Fiction&>(rhs);
      if (this->title == aFiction.title) {
         if (this->first == aFiction.first) {
            if (this->last == aFiction.last) {
               return true;
            }
         }
      }
   }
   return false;
}

//--------------------------------------------------------------------------
//operator !=
//determines if two fiction books are not equal using title, first and
//last name
bool Fiction::operator!=(const Item& rhs) const
{
   return !(*this == rhs);
}

//--------------------------------------------------------------------------
//operator <
//determines if two fiction books are less than using title, first and
//last name
bool Fiction::operator<(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Fiction& aFiction = static_cast<const Fiction&>(rhs);
      if (this->last != aFiction.last) {
         if (this->last < aFiction.last) {
            return true;
         }
      }
      else if (this->first != aFiction.first) {
         if (this->first < aFiction.first) {
            return true;
         }
      }
      else {
         if (this->title != aFiction.title) {
            if (this->title < aFiction.title) {
               return true;
            }
         }
      }
   }
   return false;
}

//--------------------------------------------------------------------------
//operator >
//determines if two fiction books are greater than using title, first and
//last name
bool Fiction::operator>(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Fiction& aFiction = static_cast<const Fiction&>(rhs);
      if (this->last != aFiction.last) {
         if (this->last > aFiction.last) {
            return true;
         }
      }
      else if (this->first != aFiction.first) {
         if (this->first > aFiction.first) {
            return true;
         }
      }
      else {
         if (this->title != aFiction.title) {
            if (this->title > aFiction.title) {
               return true;
            }
         }
      }
   }
   return false;
}
