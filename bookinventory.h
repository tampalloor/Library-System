//---------------------------------------------------------------------------
// BookInventory.h
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

#ifndef BOOKINVENTORY_H_
#define BOOKINVENTORY_H_

#include "item.h"
#include "fiction.h"
#include "children.h"
#include "periodical.h"
#include <iostream>
#include <iomanip>
using namespace std;

class BookInventory
{
public:
    //--------------------------------------------------------------------
    // Default Constructor
    BookInventory();
    //-------------------------------------------------------------------
    // Destructor
    ~BookInventory();
    //-------------------------------------------------------------------
    // Checks if the Binary Tree contains any book item nodes  
    bool isEmpty() const;
    //-------------------------------------------------------------------
    // Empty all book item nodes contained in the Binary Tree    
    void makeEmpty();

    //-------------------------------------------------------------------
    // Inserts a book item node contained in the Binary Tree
    bool insert(Item*);

    //-------------------------------------------------------------------
    // Retrieves a book item node contained in the Binary Tree 
    bool retrieve(const Item&, Item*&) const;

    void print(char ch); 
    //-------------------------------------------------------------------
    // Print out all book item nodes contained in the Binary Tree inorder
    void inOrderPrint() const;

private:
    struct Node
    {
        Item* data;
        Node* left;
        Node* right;
    };
    Node* root;

    // helper function for inOrderPrint
    void inOrderHelper(Node*) const;

    // helper function for retrieve
    bool retrieveHelper(const Item&, Item*&, Node*) const;

    // helper function for makeEmpty
    void makeEmptyHelper(Node*);
};
#endif