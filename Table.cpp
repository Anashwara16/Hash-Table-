
// Table.cpp  Table class implementation

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;

// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"

//*************************************************************************

/*
 * Representation invariant: The names and scores in the Table object are stored in an array of type Node*.
 * If no name is present in the array entry, then the array entry is considered to be null.
 *
 */

// Initialize Table class using default table size.
Table::Table()
{

   hashTable = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;

   for (int i = 0; i < hashSize; i++)
   {
      hashTable[i] = NULL;
   }
}

/*
 * Initialize Table class with a hash size input by the user.
 * @param hSize - size of the hash table.
 */
Table::Table(unsigned int hSize)
{

   hashTable = new ListType[hSize]();
   hashSize = hSize;

   for (int i = 0; i < hashSize; i++)
   {
      hashTable[i] = NULL;
   }
}

/*
 * Lookup a name in the hash table.
 * @param key - key of the entry.
 * @return pointer to the score corresponding to key.
 */
int *Table::lookup(const string &key)
{

   return listLookUp(hashTable[hashCode(key)], key);
}

/*
 * Remove a certain key-value pair from the hash table.
 * @param key - key of the entry.
 * @return true after removing the entry successfully.
 */
bool Table::remove(const string &key)
{

   int hashIndex = hashCode(key);

   return listRemove(hashTable[hashIndex], key);
}

/*
 * Insert a key-value pair into the hash table.
 * @param key - key of the entry.
 * @return true if the entry has been inserted into the hash table successfully.
 */
bool Table::insert(const string &key, int value)
{

   int hashIndex = hashCode(key);

   return listInsert(hashTable[hashIndex], key, value);
}

/*
 * Count the number of entries in the hash table.
 * @return count of entries.
 */
int Table::numEntries() const
{

   int count = 0;

   for (int i = 0; i < hashSize; i++)
   {

      count += numListEntries(hashTable[i]);
   }

   return count;
}

/*
 * Print all the entries in the hash table.
 */
void Table::printAll() const
{

   for (int i = 0; i < hashSize; i++)
   {

      printListEntries(hashTable[i]);
   }
}

/*
 * Print out the hash table statistics.
 * The number of buckets, the number of entries, the number of non-empty buckets, and the longest chain
 */
void Table::hashStats(ostream &out) const
{

   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntries() << endl;
   out << "number of non-empty buckets: " << getNonEmptyBucketsCount() << endl;
   out << "longest chain: " << getLongestChain() << endl;
}

// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const
{

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;
}

// add definitions for your private methods here

/*
 * Count the number of non-empty buckets in the hash table.
 * @return the number of non-empty buckets in the hash table.
 */
int Table::getNonEmptyBucketsCount() const
{

   int nonEmptyBuckets = 0;

   for (int i = 0; i < hashSize; i++)
   {

      if (hashTable[i] != NULL)
      {

         nonEmptyBuckets++;
      }
   }

   return nonEmptyBuckets;
}

/* Find the longest chain item in the hash table.
 * @return the longest chain item in the hash table.
 */
int Table::getLongestChain() const
{

   int longestChain = 0;
   int currLength = 0;

   for (int i = 0; i < hashSize; i++)
   {

      currLength = numListEntries(hashTable[i]);

      if (currLength > longestChain)
      {
         longestChain = currLength;
      }
   }

   return longestChain;
}
