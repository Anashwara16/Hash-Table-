

#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue)
{

   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n)
{

   key = theKey;
   value = theValue;
   next = n;
}

//*************************************************************************
// put the function definitions for your list functions below

/*
 * Insert the key and value to the front of the list. If the key-value pair already exists, then do not insert.
 * @param list: the list to insert the entry.
 * @param key - key of the entry.
 * @param value - value of the entry.
 * @return true if the insertion is successful.
 */
bool listInsert(ListType &list, string key, int value)
{

   ListType node = list;

   if (node == NULL)
   {
      list = new Node(key, value, list);
      return true;
   }

   while (node->next != NULL)
   {

      if (node->key == key)
      {
         return false;
      }

      node = node->next;
   }

   if (node->key == key)
   {

      return false;
   }

   node->next = new Node(key, value);

   return true;
}

/*
 * Search the key-associated key-value pair in the list.
 * @param target - key of the entry.
 * @return pointer to the corresponding value. If the key is not present, return null.
 */
int *listLookUp(ListType list, string target)
{

   ListType node = list;

   while (node != NULL)
   {

      if (node->key == target)
      {

         return &node->value;
      }

      node = node->next;
   }

   return NULL;
}

/*
 * Remove the key-value pair from the list. Also frees memory of the node.
 * @param target - key of the entry.
 * @return true if the removal was done successfully; else false.
 */
bool listRemove(ListType &list, string target)
{

   ListType node = list;

   if (node == NULL)
   {
      return false;
   }

   if (node->key == target)
   {

      ListType temp = node->next;

      delete node;

      list = temp;

      return true;
   }

   ListType prev = node;

   node = node->next;

   while (node != NULL)
   {

      if (node->key == target)
      {

         prev->next = node->next;

         delete node;

         return true;
      }

      else
      {
         prev = node;
         node = node->next;
      }
   }
   return false;
}

/*
 * Get the number of entries in the list.
 * @param list - the list to be used.
 * @return number of entries in the list.
 */
int numListEntries(ListType list)
{

   int count = 0;

   ListType node = list;

   while (node != NULL)
   {

      count++;

      node = node->next;
   }

   return count;
}

/*
 * Print all the entries (key-value pairs) in the list.
 * @param list - list to be printed.
 */
void printListEntries(ListType list)
{

   ListType node = list;

   while (node != NULL)
   {

      cout << node->key << " " << node->value << endl;

      node = node->next;
   }
}
