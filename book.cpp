#include "book.h"
//---------------------------------------------------------------------------
// book.cpp
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

//---------------------------------------------------------------------------
// Default constructor
// Preconditions:   None
// Postconditions:  initializes values 
Book::Book()
{
   bookType = 'X'; 
   year = 0; 
}


//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  None
Book::~Book()
{
}


//---------------------------------------------------------------------------
// getYear
// Preconditions:   year is initialized 
// Postconditions:  returns year 
int Book::getYear() const
{
   return year;
}

//---------------------------------------------------------------------------
// getFormat
// Preconditions:   format is initialized 
// Postconditions:  returns format 
char Book::getFormat() const
{
   return bookType;
}

//---------------------------------------------------------------------------
// getType
// Preconditions:   type is initialized 
// Postconditions:  returns book type 
char Book::getType() const
{
   return bookType;
}

//---------------------------------------------------------------------------
// setYear
// Preconditions:   year is a valid year
// Postconditions:  sets year 
void Book::setYear(int date)
{
   year = date; 
}

//---------------------------------------------------------------------------
// setFormat
// Preconditions:   format is a valid format
// Postconditions:  sets book type and format 
void Book::setFormat(char ch)
{
   bookType = ch;
   itemFormat = ch; 
}

//---------------------------------------------------------------------------
// setTitle
// Preconditions:   title is a valid title 
// Postconditions:  sets title 
void Book::setTitle(string newTitle)
{
   title = newTitle; 
}

//---------------------------------------------------------------------------
// print
// Preconditions:   None
// Postconditions:  None
void Book::print() const
{
}
