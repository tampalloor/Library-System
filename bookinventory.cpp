#include "bookinventory.h"
//---------------------------------------------------------------------------
// BookInventory.cpp
// Class representing the inventory of book items in the library
//---------------------------------------------------------------------------
// BookInventory class: Represented by a Binary Tree of Book Items
//
// Implementation and assumptions:
// - Inherits from Item class and assumes the class has been defined
// - Utilizes common binary search tree methods, such insert, retrieve,
// deleting all nodes, and print all nodes in order, and these method can be
// applies for all the different book items in the library. 
// - Assumes that item class and its derived class contain comparative 
// operators (<,>,==,!=)
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Default constructor
// Preconditions:   None
// Postconditions:  root points to nullptr
BookInventory::BookInventory()
{
   root = nullptr; 
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   Data points to memory on the heap
// Postconditions:  root for inventory is deallocated
//                  All Data in the inventory is deallocated
BookInventory::~BookInventory()
{
   makeEmpty();
}

//---------------------------------------------------------------------------
// isEmpty
// Preconditions:  None
// Postconditions: Returns true if root = nullptr
//                 Returns False otherwise
bool BookInventory::isEmpty() const
{
   return root == nullptr;
}

//---------------------------------------------------------------------------
// makeEmpty
// Preconditions:  None
// Postconditions: Empties entire Binree and deallocates memory
void BookInventory::makeEmpty()
{
   if (isEmpty())
   {
      return;
   }
   makeEmptyHelper(root); // helper
   root = nullptr;
}

//---------------------------------------------------------------------------
// insert
// Preconditions:   dataptr is a valid Item pointer
// Postconditions:  Returns true if the value is successfully inserted
//						  Checks if value is greater than or less than current node
//                  and inserts accordingly
//						  Doesn't insert duplicates value and returns false
bool BookInventory::insert(Item* dataptr)
{
    Node* ptr = new Node; // exception is thrown if memory is not allocated
    ptr->data = dataptr;
    ptr->left = ptr->right = nullptr;
    if (isEmpty())
    {
        root = ptr;
    }
    else
    {
        Node* current = root;
        bool inserted = false;
        // if item is less than current item, insert in left subtree,
        // otherwise insert in right subtree
        while (!inserted)
        {
            if (*ptr->data < *current->data)
            {

                if (current->left == nullptr)
                { // at leaf, insert left
                    current->left = ptr;
                    dataptr = nullptr;
                    inserted = true;
                }
                else
                    current = current->left; // one step left
            }
            else if (*ptr->data == *current->data)
            {
                delete ptr;
                return false;
            }
            else
            {

                if (current->right == nullptr)
                { // at leaf, insert right
                    current->right = ptr;
                    dataptr = nullptr;
                    inserted = true;
                }
                else {
                    current = current->right; // one step right
                }
            }
        }
    }
    return true;
}

//---------------------------------------------------------------------------
// retrieve
// Preconditions:   Current and parent are valid Node Pointers
// Postconditions:  Returns true if target is found
//                  Sets storage to the retrieved node
//                  Returns false otherwise, storage is filled with garbage
bool BookInventory::retrieve(const Item& target, Item*& storage) const
{
   return retrieveHelper(target, storage, root);
}

//---------------------------------------------------------------------------
// retrieveHelper
// Preconditions:   Current and parent are valid Node Pointers
// Postconditions:  Returns true if target is found
//                  Sets storage to the retrieved node
//                  Returns false otherwise, storage is filled with garbage
bool BookInventory::retrieveHelper(const Item& target, Item*& storage, 
    Node* current) const
{
    
    if (current == nullptr)
    {
        storage = nullptr;
        return false;
    }
   // cout << current->data->getTitle() << endl;
    if (*current->data == target)
    {
        storage = current->data;
        return true;
    }
    if (*current->data > target)
    {
        return retrieveHelper(target, storage, current->left);
    }
    return retrieveHelper(target, storage, current->right);
}

//---------------------------------------------------------------------------
// print
// Preconditions: Parameter object have valid char
// Postconditions: Prints all of the books aspects
void BookInventory::print(char ch)
{
   if (ch == 'F' || ch == 'C') {
      cout << left << setw(15) << "AVAIL" << setw(25) << "Author"
           << setw(55) << "Title" << setw(10) << "Year" << endl;
      this->inOrderPrint();
   }
   else if (ch == 'P') {
      cout << left << setw(15) << "AVAIL" << setw(30) << "Title" 
           << setw(25) << "Month" << setw(4) << "Year" << endl;
      this->inOrderPrint();
   }
}

//---------------------------------------------------------------------------
// inOrderPrint
// Preconditions: None
// Postconditions: Prints values for the the BinTree (InOrder Traversal)
//						 If it is empty then it will print nothing
//                 Prints endl at the end of the traversal
void BookInventory::inOrderPrint() const
{
   inOrderHelper(root);
}

//---------------------------------------------------------------------------
// inorderHelper
// Helper for the output operator
// Preconditions: Parameter object have valid BinTree tree
// Postconditions: Prints values for the the BinTree (InOrder Traversal)
//						 If it is empty then it will print nothing
//                 Prints endl at the end of the traversal
void BookInventory::inOrderHelper(Node* current) const
{
   if (current == nullptr)
   {
      return;
   }
   inOrderHelper(current->left);
   if (current->data->getFormat() == 'F') {
      const Fiction& aFiction = static_cast<const Fiction&>(*current->data);
      string name = aFiction.getLastName() + " " + aFiction.getFirstName(); 
      cout << left << setw(15) << aFiction.getNumCopies()  << setw(25)
           << name << setw(55) << aFiction.getTitle() << setw(10) 
           << aFiction.getYear() << endl;
   }
   else if (current->data->getFormat() == 'C') {
      const Children& aChildren = static_cast<const Children&>(*current->data);
      string name = aChildren.getLastName() + " " + aChildren.getFirstName();
      cout << left << setw(15) << aChildren.getNumCopies() << setw(25)
           << name << setw(55) << aChildren.getTitle() << setw(10) 
           << aChildren.getYear() << endl;
   }
   else if(current->data->getFormat() == 'P') {
      const Periodical& aPeriodical = static_cast<const Periodical&>
           (*current->data);
      cout << left << setw(15) << aPeriodical.getNumCopies() << setw(30) 
           << aPeriodical.getTitle() << setw(5) << right <<aPeriodical.getMonth() 
           << setw(24) << aPeriodical.getYear() << endl;
   }
   inOrderHelper(current->right);
}

//---------------------------------------------------------------------------
// makeEmptyHelper
// Preconditions:  None
// Postconditions: Empties entire Binree and deallocates memory
void BookInventory::makeEmptyHelper(Node* current)
{
    if (current == nullptr)
    {
        return;
    }
    if (current->left != nullptr)
    {
        makeEmptyHelper(current->left); // recursive call to left node
    }
    if (current->right != nullptr)
    {
        makeEmptyHelper(current->right); // recursive call to right node
    }
    delete current->data;
    current->data = nullptr;
    delete current;
    current = nullptr;
}
