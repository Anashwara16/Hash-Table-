

//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>

struct Node
{
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};

typedef Node *ListType;

//*************************************************************************
// add function headers (aka, function prototypes) for your functions
// that operate on a list here (i.e., each includes a parameter of type
// ListType or ListType&).  No function definitions go in this file.

/*
 * Remove the key-value pair from the list. Also frees memory of the node.
 * @param target - key of the entry.
 * @return true if the removal was done successfully; else false.
 */
bool listRemove(ListType &list, std::string target);

/*
 * Insert the key and value to the front of the list. If the key-value pair already exists, then do not insert.
 * @param list: the list to insert the entry.
 * @param key - key of the entry.
 * @param value - value of the entry.
 * @return true if the insertion is successful.
 */
bool listInsert(ListType &list, std::string key, int value);

/*
 * Search the key-associated key-value pair in the list.
 * @param target - key of the entry.
 * @return pointer to the corresponding value. If the key is not present, return null.
 */
int *listLookUp(ListType list, std::string target);

/*
 * Get the number of entries in the list.
 * @param list - the list to be used.
 * @return number of entries in the list.
 */
int numListEntries(ListType list);

/*
 * Print all the entries (key-value pairs) in the list.
 * @param list - list to be printed.
 */
void printListEntries(ListType list);

// keep the following line at the end of the file
#endif
