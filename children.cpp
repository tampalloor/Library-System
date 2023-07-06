#include "children.h"
//---------------------------------------------------------------------------
// childrens.cpp
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

//--------------------------------------------------------------------------
//default destructor
//None
Children::Children()
{
}

//--------------------------------------------------------------------------
//destructor
//None
Children::~Children()
{
}

//--------------------------------------------------------------------------
//getYear
//returns year of current book
int Children::getYear() const
{
   return year;
}

//--------------------------------------------------------------------------
//getFormat
//returns format of current book
char Children::getFormat() const
{
   return itemFormat;
}

//--------------------------------------------------------------------------
//getType
//returns type of current book
char Children::getType() const
{
   return 'C';
}

//--------------------------------------------------------------------------
//setYear
//sets year of current book
void Children::setYear(int date)
{
   year = date; 
}

//--------------------------------------------------------------------------
//setFortmat
//sets format of current book
void Children::setFormat(char ch)
{
   itemFormat = ch; 
   bookType = ch; 
}

//--------------------------------------------------------------------------
//getFirstName 
//returns the authors first name of the current book 
string Children::getFirstName() const
{
   return first;
}

//--------------------------------------------------------------------------
//getLastName 
//gets the authors last name of the current book 
string Children::getLastName() const
{
   return last;
}

//--------------------------------------------------------------------------
//setFirstName  
//sets the authors first name of the current book 
void Children::setFirstName(string newName)
{
   first = newName;
}

//--------------------------------------------------------------------------
//setlastName   
//sets the authors last name of the current book
void Children::setLastName(string newName)
{
   last = newName; 
}

//--------------------------------------------------------------------------
//getMonth    
//returns -1 since children book have no month 
int Children::getMonth() const
{
   return -1;
}

//--------------------------------------------------------------------------
//create    
//None 
Item* Children::create() const
{
  return nullptr;
}

//--------------------------------------------------------------------------
//setData
//reads in the file and sets fiction variables accordingly 
bool Children::setData(istream& file)
{
   this->bookType = 'C';
   itemFormat = bookType; 
   file.get();

   string author;
   file >> author; 
   this->last = author;

   file.get(); 
   getline(file, author, ','); 
   this->first = author; 

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
bool Children::setTransactionData(istream& file)
{
   string firstName;
   string lastName;
   string title;

   getline(file, title, ',');
   setTitle(title);
   file.get();
   file >> lastName;
   this->last = lastName; 

   file.get();
   getline(file, firstName, ',');
   this->first = firstName; 
   setFormat('C');

   return true;
}

//--------------------------------------------------------------------------
//print
//used for display history 
void Children::print() const
{
   cout << " " << title << "   " << last << " " << first << "    " << year; 
}

//--------------------------------------------------------------------------
//operator ==
//determines if two fiction books are equal using title, first and last name
bool Children::operator==(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Children& aChild = static_cast<const Children&>(rhs);
      if (this->title == aChild.title) {
         if (this->first == aChild.first && this->last == aChild.last) {
            return true; 
         }
      }
   }
   return false;
}

//--------------------------------------------------------------------------
//operator !=
//determines if two fiction books are not equal using title, first and
//last name
bool Children::operator!=(const Item& rhs) const
{
   return !(*this == rhs);
}

//--------------------------------------------------------------------------
//operator <
//determines if two fiction books are less than using title, first and
//last name
bool Children::operator<(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Children& aChild = static_cast<const Children&>(rhs);
      if (this->title != aChild.title) {
         if (this->title < aChild.title) {
            return true; 
         }
      }
      else {
         if (this->last != aChild.last) {
            if (this->last < aChild.last) {
               return true;
            }
         }
         else if (this->first != aChild.first) {
            if (this->first < aChild.first) {
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
bool Children::operator>(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Children& aChild = static_cast<const Children&>(rhs);
      if (this->title != aChild.title) {
         if (this->title > aChild.title) {
            return true;
         }
      }
      else {
         if (this->last != aChild.last) {
            if (this->last > aChild.last) {
               return true;
            }
         }
         else if (this->first != aChild.first) {
            if (this->first > aChild.first) {
               return true;
            }
         }
      }
   }
   return false;
}
