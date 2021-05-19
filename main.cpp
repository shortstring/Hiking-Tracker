//Ashton Smith CS202 Program 2
//main.cpp
//This file contains the main and a menu to interact with the classes.
#include "dll.h"
using namespace std;
int menu();
int add(list & my_dll);



//
int main()
{	
	menu();
	return 0;
}



//This function provides a menu to interact with acitivities.
int menu(){
	list dll;
	int option = 0;
	do{
		cout << "What would you like to do? " << endl;
		cout << "1. Display all " << endl;
		cout << "2. Display a specific priority " << endl;
		cout << "3. Add an activity " << endl;
		cout << "4. Remove an activity " << endl;
		cout << "5. Exit program " << endl;
		cin >> option;
		cin.ignore(100 ,'\n');
		switch(option){
			case 1: 
				dll.display_all();
				break;
			case 2:
				dll.display_priority();
				break;
			case 3:
				add(dll);
				break;
			case 4:
				dll.remove();
				break;
			default:
				break;

		}
	}while(option != 5);
}



//This function allows the user to add a new activity.
int add(list & my_dll){
	int option = 0;
	activity * obj;
	do{
	cout << "What type of activity would you like to add?" << endl;
	cout << "Enter the number next to the type." << endl;
	cout << "1. Hiking" << endl;
	cout << "2. Dining" << endl;
	cout << "3. Show" << endl;
	cin >> option;
	cin.ignore(100, '\n');
	if(option == 1)
		obj = new hiking;
	else if(option == 2)
		obj = new dining;
	else if(option == 3)
		obj = new show;
	}while(option < 1 || option > 3);
	obj -> add();
	my_dll.add(obj);
	return 0;
}

