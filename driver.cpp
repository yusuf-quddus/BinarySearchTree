
// Yusuf Quddus 
// Nathan Wong 
// Lab 5

/*
Psuecode:
Request file location from user
loop until valid vile is entered
open file
while not end of file read in data into person objects and
send person objects into binary search tree
print tree data in infix order by birthday
print tree data in breadth first order by birthday
print tree data in prefix order by name
print tree data in postfix order by name
delete the pN node in the BST
output new tree
empty name tree
empty birthday tree
output data from empty trees which should empty
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"
#include "BST_Node.h"
#include "BinarySearchTree.h"


using namespace std;

int main()
{
	bool loop = 0;
	string fileLocation = "",
		fname = "",
		lname = "",
		birthday = "";
	ifstream inFile;
	ofstream outFile;
	int size = 0;


	BinarySearchTree <Person> pBirthday;
	BinarySearchTree <Person> pName;
	Person Pb("", "", "birthday");
	Person Pn("", "", "name");
	do
	{
		cout << "Enter the file location of your input file: " << endl;
		getline(cin, fileLocation);

		inFile.open(fileLocation);
		// if file can't be opened 
		if (inFile.fail())
		{
			loop = 1;
			cout << "Please Try Again, input file is not found" << endl;
		}
		else
			loop = 0;
	} while (loop);

	while (inFile >> fname && inFile >> lname && inFile >> birthday)
	{
		string name = fname + " " + lname;
		Pb.setName(name);
		Pb.setBirthday(birthday);
		pBirthday.insertData(pBirthday.getRoot(), Pb);
	}

	inFile.close();

	inFile.open(fileLocation);

	while (inFile >> fname && inFile >> lname && inFile >> birthday)
	{
		string name = fname + " " + lname;
		Pn.setName(name);
		Pn.setBirthday(birthday);
		pName.insertData(pName.getRoot(), Pn);
	}

	inFile.close();


	cout << "==================================================" << endl;
	outFile.open("BirthdaysOutput.txt");

	cout << "Birthday infix: " << endl;
	outFile << "\nBirthday infix: " << endl << endl;
	pBirthday.inPrintData(outFile, pBirthday.getRoot());
	cout << endl;

	cout << "Birthday breadth first: " << endl;
	outFile << "\nBirthday breadth first: " << endl << endl;
	pBirthday.breadthFirstPrint(outFile, pBirthday.getRoot());
	cout << endl;

	outFile.close();
	cout << "==================================================" << endl;
	outFile.open("NamesOutput.txt");

	cout << "Name pre: " << endl;
	outFile << "\nName pre: " << endl << endl;
	pName.prePrintData(outFile, pName.getRoot());
	cout << endl;

	cout << "Name post: " << endl;
	outFile << "\nName post: " << endl << endl;
	pName.postPrintData(outFile, pName.getRoot());
	cout << endl;

	outFile.close();

	system("pause");
	return 0;
}
