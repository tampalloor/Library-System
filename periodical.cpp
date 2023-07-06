#include "periodical.h"
//---------------------------------------------------------------------------
// periodical.cpp
// Derived class of Book class for Periodicals
//---------------------------------------------------------------------------
// Periodical class Implementation and assumptions:  
//   -- Item* create() function returns new Periodical object for use
//      in factory class
//   -- setData function sets all data members for periodical from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of month data member
//   -- Comparison overloads reflect sorting criteria of periodical 
//      class: sorted by year, then month, then title. No other data used 
//      for sorting, and criteria uniquely identifies each periodical.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default constructor 
//None
Periodical::Periodical()
{
   month = 0; 
}

//--------------------------------------------------------------------------
//destructor
//None
Periodical::~Periodical()
{
}

//--------------------------------------------------------------------------
//getMonth
//returns month
int Periodical::getMonth() const
{
  return month;
}

//--------------------------------------------------------------------------
//setMonth 
//sets month
void Periodical::setMonth(int date)
{
   month = date; 
}

//--------------------------------------------------------------------------
//getLastName
//return none since Periodicals have no author 
string Periodical::getLastName() const
{
   return "";
}

//--------------------------------------------------------------------------
//getFirstName
//return none since Periodicals have no author 
string Periodical::getFirstName() const
{
   return "";
}

//--------------------------------------------------------------------------
//create
//None
Item* Periodical::create() const
{
   return nullptr;
}

//--------------------------------------------------------------------------
//setData
//reads in the file and sets fiction variables accordingly 
bool Periodical::setData(istream& file)
{
   file.get(); 
   string title; 
   getline(file, title, ','); 
   file.get(); 

   int month; 
   file >> month; 
   this->setMonth(month);

   int year; 
   file >> year; 
   this->setYear(year); 


   this->title = title; 
   this->bookType = 'P'; 
   this->copies = 1; 
   itemFormat = bookType;

   return true;
}

//--------------------------------------------------------------------------
//setTransactionData 
//reads in the file and sets transaction variables accordingly 
bool Periodical::setTransactionData(istream& file)
{
   string firstName;
   string lastName;
   string title;
   int month;
   int year;
   file >> year;
   this->setYear(year);
   file.get();
   file >> month;
   this->setMonth(month);
   file.get();
   getline(file, title, ',');
   this->setTitle(title);
   this->setFormat('P');
   return true;
}

//--------------------------------------------------------------------------
//print
//used for display history 
void Periodical::print() const
{
   cout << " " << month << " " << year << " " << title;
}

//--------------------------------------------------------------------------
//operator ==
//determines if two periodical books are equal using title, first and last 
//name 
bool Periodical::operator==(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Periodical& aPeriodical = static_cast<const Periodical&>(rhs);
      if (this->title == aPeriodical.title) {
         if (this->year == aPeriodical.year) {
            if (this->month == aPeriodical.month) {
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
bool Periodical::operator!=(const Item& rhs) const
{
   return !(*this == rhs);
}


//--------------------------------------------------------------------------
//operator <
//determines if two fiction books are less than using title, first and
//last name
bool Periodical::operator<(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Periodical& aPeriodical = static_cast<const Periodical&>(rhs);
      if (this->year != aPeriodical.year) {
         if (this->year < aPeriodical.year) {
            return true;
         }
      }
      else if(this->month != aPeriodical.month) {
         if (this->month < aPeriodical.month) {
            return true;
         }
      }
      else if(this->title != aPeriodical.title) {
         if (this->title < aPeriodical.title) {
            return true; 
         }
      }
   }
   return false;
}

//--------------------------------------------------------------------------
//operator >
//determines if two fiction books are greater than using title, first and
//last name
bool Periodical::operator>(const Item& rhs) const
{
   if (this->bookType == rhs.getFormat()) {
      const Periodical& aPeriodical = static_cast<const Periodical&>(rhs);
      if (this->year != aPeriodical.year) {
         if (this->year > aPeriodical.year) {
            return true;
         }
      }
      else if (this->month != aPeriodical.month) {
         if (this->month > aPeriodical.month) {
            return true;
         }
      }
      else if (this->title != aPeriodical.title) {
         if (this->title > aPeriodical.title) {
            return true;
         }
      }
   }
   return false;
}
