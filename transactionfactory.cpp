#include "transactionfactory.h"
// Derived class of Factory class for returning transaction objects
//---------------------------------------------------------------------------
// Transactionfactory class Implementation and assumptions:  
//   -- Item* createObject(char) function returns new Transaction object, 
//      where the type of transaction is determined by input char 
//      ('C' for checkout, 'R' for return, 'H' for displaying a patron's
//      history).
//   -- objFactory data member is array of Transaction*, where each each 
//      index maps to a particular transaction type. 
//   -- Hashing function used to map a given char value to index of array
//   -- Invalid input chars return null pointers
//
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
//default destructor
//intializes objFactory 
TransactionFactory::TransactionFactory()
{
   for (int i = 0; i < 26; i++)
   {
      objFactory[i] = nullptr;
   }
}

//--------------------------------------------------------------------------
//destructor
//deallocates objFactory 
TransactionFactory::~TransactionFactory()
{
   for (int i = 0; i < 26; i++) {
      delete objFactory[i]; 
      objFactory[i] = nullptr;
   }
}

//--------------------------------------------------------------------------
//createObject
//Creates the necassary transaction objects
Transaction* TransactionFactory::createObject(char ch) const
{
   switch (ch) {
   case 'R':
      return new Return();
      break;
   case 'C':
      return new Checkout();
      break;
   case 'H':
      return new DisplayHistory();
      break;
   case 'D':
      return new Display(); 
      break; 
   default: //cases which arent checkout or return or display
      return nullptr;
   }
}