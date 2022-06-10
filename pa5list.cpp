

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"
typedef Node *ListType;

int main()
{

   const string s = "Number";
   Node *list = NULL;
   Node *head = list;

   listInsert(head, "Ana", 30);
   listInsert(head, "Pri", 33);
   listInsert(head, "Reggie", 40);

   int *search = listLookUp(head, e);
   if (search != NULL)
   {
      cout << "Found, searching for: " << search->key << " Value: " << search->value << endl;
   }
   else
   {
      cout << "Not found, searching for:" << e << endl;
   }

   printListEntries(head);
   cout << endl;

   cout << "Number of elements: " << numListEntries(head) << endl;
   cout << endl;

   cout << "Deleting" << endl;
   bool del = listRemove(head, "Mary");
   cout << "Deleted? " << del << endl;

   printListEntries(head);

   return 0;
}
