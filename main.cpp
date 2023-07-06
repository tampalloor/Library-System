#include "library.h"
#include <istream>

int main() {
   Library currentLibrary;
   ifstream books("data4books.txt");
   ifstream transactions("data4commands.txt");
   ifstream patrons("data4patrons.txt");
   currentLibrary.addBooks(books);
   currentLibrary.addPatrons(patrons);
   currentLibrary.processTransactions(transactions);
}