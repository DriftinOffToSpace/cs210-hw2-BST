#include "BinarySearchTree.h"
using namespace std;

int main() {
	bool program_run = true;
	int selection;
	cout << "Welcome to the Binary Search Tree (BST) Simulator. Please see the options below..." << endl << endl;
	cout << "1 - INSERT - Inserts a given record into the BST." << endl;
	cout << "2 - REMOVE - Removes a record with the given ID." << endl;
	cout << "3 - FIND - Search for and return a record given an ID number." << endl;
	cout << "4 - FIND MIN - Returns the record with the lowest ID number." << endl;
	cout << "5 - FIND MAX - Returns the record with the highest ID number" << endl;
	cout << "6 - MAKE EMPTY - Clears the tree of all records, rendering it empty." << endl;
	cout << "7 - REPORT - Prints a listing of all record in ascending order by ID number, along with the level at which each record is stored." << endl;
	cout << "0 - EXIT - Safely exits the program. No work will be saved." << endl;
	
	while (program_run)
	{
		cout << endl << "What would you like to do? Please make a selection 1-7 or 0." << endl << "Selection:  ";
		cin >> selection;

		switch (selection)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 0:
			program_run = false;
			cout << "Thank you for using the simulator. Goodbye." << endl;
			break;
		}	
	}
	exit(3);
}