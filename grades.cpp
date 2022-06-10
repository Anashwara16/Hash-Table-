

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 *
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

void handleInput(Table *grades);
void infoCommands(Table *grades, string command);
void insert(Table *grades);
void change(Table *grades);
void lookup(Table *grades);
void remove(Table *grades);
void help();

int main(int argc, char *argv[])
{

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table *grades; // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1)
   {
      hashSize = atoi(argv[1]); // atoi converts c-string to int

      if (hashSize < 1)
      {
         cout << "Command line argument (hash size) must be a positive number."
              << endl;
         return 1;
      }

      grades = new Table(hashSize);
   }
   else
   { // no command line args given -- use default table size
      grades = new Table();
   }

   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   handleInput(grades);

   return 0;
}

/*
 * Handles user input and calls corresponding functions based on the command.
 * @param grades - Table object that will contain students' scores and corresponding functions.
 */
void handleInput(Table *grades)
{

   string command = "";

   while (true)
   {

      cout << "cmd> ";
      cin >> command;

      if (command == "quit")
      {
         delete grades;
         return;
      }

      else if (command == "insert")
      {
         insert(grades);
      }

      else if (command == "change")
      {
         change(grades);
      }

      else if (command == "lookup")
      {
         lookup(grades);
      }

      else if (command == "remove")
      {
         remove(grades);
      }

      else
      {
         infoCommands(grades, command);
      }
   }
}

/*
 * Performs additional commands which give information about the grades table.
 * @param grades - Table object that will contain students' scores and corresponding functions.
 * @param command - the command requested by the user.
 */
void infoCommands(Table *grades, string command)
{

   if (command == "print")
   {
      grades->printAll();
   }

   else if (command == "size")
   {
      cout << grades->numEntries() << endl;
   }

   else if (command == "stats")
   {
      grades->hashStats(cout);
   }

   else if (command == "help")
   {
      help();
   }

   else
   {
      cout << "ERROR: invalid command" << endl;
   }
}

/*
 * Insert a student and their corresponding score into the grades table.
 * Prints a message if the name is already present.
 * @param grades - the table object that contains students' scores.
 */
void insert(Table *grades)
{

   string key;
   int value;
   cin >> key;
   cin >> value;

   if (!grades->insert(key, (int)value))
   {
      cout << "Student's name is already present in the table." << endl;
   }
}

/*
 * Performs lookup of a student and updates their corresponding score.
 * Prints a message if the name is absent.
 * @param grades - the table object that contains students' scores.
 */
void change(Table *grades)
{

   string key;
   int value;
   cin >> key;
   cin >> value;
   int *val = grades->lookup(key);

   if (val == NULL)
   {
      cout << "This student's name is not present in the table." << endl;
   }

   else
   {
      *val = value;
   }
}

/*
 * Performs lookup of a student and prints the corresponding score.
 * Prints a message if the name is absent.
 * @param grades - the table object that contains students' scores.
 */
void lookup(Table *grades)
{

   string key;
   cin >> key;
   int *val = grades->lookup(key);

   if (val == NULL)
   {
      cout << key << " is not present in the table." << endl;
   }

   else
   {
      cout << key << "'s score is: " << *val << endl;
   }
}

/*
 * Removes a student's name and score (key-value pair) from the table.
 * Prints a message if the name is absent.
 * @param grades - the table object that contains students' scores.
 */
void remove(Table *grades)
{

   string key;

   cin >> key;

   if (!grades->remove(key))
   {
      cout << key << " is not present in the grade table." << endl;
   }
}

/*
 * Prints all the available commands, when user enters 'help' command.
 */
void help()
{

   cout << "List of valid commands are:" << endl;

   cout << "[insert, change, lookup, remove, print, size, stats, help, quit]" << endl;

   cout << "[insert] - "
        << "Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert." << endl;

   cout << "[change] - "
        << "Change the score for name. Print an appropriate message if this name isn't present." << endl;

   cout << "[lookup] - "
        << "Lookup the name, and print out his or her score, or a message indicating that student is not in the table." << endl;

   cout << "[remove] - "
        << "Remove this student. If this student wasn't in the grade table, print a message to that effect." << endl;

   cout << "[print] - "
        << "Prints out all names and scores in the table." << endl;

   cout << "[size] - "
        << "Prints out the number of entries in the table." << endl;

   cout << "[stats] - "
        << "Prints out statistics about the hash table at this point." << endl;

   cout << "[help] - "
        << "Prints out a brief command summary." << endl;

   cout << "[quit] - "
        << "Exits the program." << endl;
}