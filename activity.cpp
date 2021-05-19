//Ashton Smith CS202 Program 2
//activity.cpp
//This .cpp file contains all of the functiosn for the activity class and classes in it's hierarchy.
#include "activity.h"
using namespace std;
const int MAX = 100;
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////					ACTIVITY CLASS					////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
activity::activity(){
	title = NULL;
	my_date = NULL;
}



//Copy constructor
activity::activity(const activity & source){
	title =  new char[strlen(source.title) +1];
	strcpy(title, source.title);
	my_date = new date(source.my_date);
}



//Destructor
activity::~activity(){
	delete[] title;
	delete my_date;
}



//Add function
int activity::add(){
	char * temp;
	temp = new char[MAX +1];
	cout << "Enter the name for the activity" << endl;
	cin.get(temp, MAX, '\n');
	cin.ignore(100 ,'\n');	
	title = new char[strlen(temp) +1];
	strcpy(title, temp);

	delete[] temp;
	set_date();
	set_length();
	set_priority();
	activity * ptr = dynamic_cast<hiking *>(this);
	if(ptr)
		set_distance();
	else{
		activity * ptr2 = dynamic_cast<dining *>(this);
		if(ptr2)
			set_cost();
		else{
			activity * ptr3 = dynamic_cast<show *>(this);
			set_live();
		}
	}
	return 1;
}



//This function cals string compare for the title.
bool activity::is_match(char * to_compare){
	if(!title)
		return true;
	else
		return strcmp(to_compare, title);
}



//This function cmpares the first three characters with the argument. Used for sorting alphabetically.
bool activity::compare_title(activity * to_comp){
	if(!this || !to_comp || !to_comp -> title || !title)
		return true;

	int length1 = strlen(title);
	int length2 = strlen(to_comp -> title);

	if(to_comp -> title && title && title[0] > to_comp -> title[0])
		return false;
	else if(length1 > 2 && length2 > 2 && title[1] > to_comp -> title[1])
		return false;
	else if(length1 > 3 && length2 > 3 && title[2] > to_comp -> title[2])
		return false;
	else if(length1 > 4 && length2 < 4)
		return false;
	else
		return true;
}


//Virtual Functions
int activity::display(){
}
int activity::set_date(){
}
int activity::set_length(){
}
int activity::set_priority(){
}
int activity::get_priority(){
}
double activity::set_distance(){
}
double activity::set_cost(){
}
bool activity::set_live(){
}



////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////					HIKING CLASS					////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
hiking::hiking(){
	title = NULL;
}



//Copy constructor
hiking::hiking(const hiking & source): activity(source)
{
	length = source.length;
	priority = source.priority;
	title =  new char[strlen(source.title) +1];
	solo = source.solo;
	time = source.length;
	distance = source.distance;
}



//Destructor
hiking::~hiking(){
}



//Returns priority
int hiking::get_priority(){
	return priority;
}



//This function calls the function to input the date.
int hiking::set_date(){
	my_date = new date;
	return my_date -> input();
}



//This function sets the length of the hike.
int hiking::set_length(){
	int temp = 0;

	cout << " How long will the hike take in minutes? " << endl;
	cin >> temp;
	cin.ignore(100 , '\n');
	length = temp;
	return temp;
}



//This function prompts the user for a priority and sets it.
int hiking::set_priority(){
	int temp = 0;
	do{
		cout << " What is the priority of this hike? Enter 1 - 10. 10 being more important. " << endl;
		cin >> temp;
		cin.ignore(100 , '\n');
		if(temp < 0 || temp > 10)
			cout << " Please enter 1 - 10" << endl;
	}while(temp < 0 || temp > 10);
	priority = temp;
	return priority;
}



//This function prompts the user for the distance of the hike.
double hiking::set_distance(){
	double temp = 0.00;
	cout << "How long is the hike in miles?" << endl;
	cin >> temp;
	cin.ignore(100 ,'\n');
	distance = temp;
	return temp;
}



//This function displays all information about the hike.
int hiking::display(){
	//convert length to hours.
	int minutes = length % 60;
	int hours = length/60;
	cout << "Hiking title: " << title << endl;
	cout << endl;
	cout << "Priority: " << priority << endl;
	cout << endl;
	cout << "Distance: " << distance << " miles." << endl;
	cout << endl;
	cout << "Length : " << hours << " hours and " << minutes << " minutes." << endl;
	cout << endl;
	my_date -> display();
	cout << "---------------------------------------------" << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////					DINING CLASS					////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
dining::dining(){
	title = NULL;
}



//Copy constructor
dining::dining(const dining & source): activity(source)
{
	length = source.length;
	priority = source.priority;
	title =  new char[strlen(source.title) +1];
	solo = source.solo;
	time = source.length;
	cost = source.cost;
}



//Destructor
dining::~dining(){
}


//Returns priority
int dining::get_priority(){
	return priority;
}



//This function calls the function to input the date.
int dining::set_date(){
	my_date = new date;
	return my_date -> input();
}



//This function sets the length of the hike.
int dining::set_length(){
	int temp = 0;

	cout << " How long will dining take in minutes? " << endl;
	cin >> temp;
	cin.ignore(100 , '\n');
	length = temp;
	return temp;
}



//This function prompts the user for a priority and sets it.
int dining::set_priority(){
	int temp = 0;
	do{
		cout << " What is the priority of this dining? Enter 1 - 10. 10 being more important. " << endl;
		cin >> temp;
		cin.ignore(100 , '\n');
		if(temp < 0 || temp > 10)
			cout << " Please enter 1 - 10" << endl;
	}while(temp < 0 || temp > 10);
	priority = temp;
	return priority;
}



//This function prompts the user for the distance of the hike.
double dining::set_cost(){
	double temp = 0.00;
	cout << "How much will this cost? In dollars." << endl;
	cin >> temp;
	cin.ignore(100 ,'\n');
	cost = temp;
	return temp;
}



//This function displays all information about the hike.
int dining::display(){
	//convert length to hours.
	int minutes = length % 60;
	int hours = length/60;
	cout << "Dining title: " << title << endl;
	cout << endl;
	cout << "Priority: " << priority << endl;
	cout << endl;
	cout << "Cost: " << cost << " dollars." << endl;
	cout << endl;
	cout << "Length : " << hours << " hours and " << minutes << " minutes." << endl;
	cout << endl;
	my_date -> display();
	cout << "---------------------------------------------" << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////					SHOW CLASS					////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
show::show(){
	title = NULL;
}



//Copy constructor
show::show(const show & source): activity(source)
{
	length = source.length;
	priority = source.priority;
	title =  new char[strlen(source.title) +1];
	solo = source.solo;
	time = source.length;
	live = source.live;
}



//Destructor
show::~show(){
}



//Returns the priority.
int show::get_priority(){
	return priority;
}



//This function calls the function to input the date.
int show::set_date(){
	my_date = new date;
	return my_date -> input();
}



//This function sets the length of the hike.
int show::set_length(){
	int temp = 0;
	cout << " How long will the show take in minutes? " << endl;
	cin >> temp;
	cin.ignore(100 , '\n');
	length = temp;
	return temp;
}



//This function prompts the user for a priority and sets it.
int show::set_priority(){
	int temp = 0;
	do{
		cout << " What is the priority of this show? Enter 1 - 10. 10 being more important. " << endl;
		cin >> temp;
		cin.ignore(100 , '\n');
		if(temp < 0 || temp > 10)
			cout << " Please enter 1 - 10" << endl;
	}while(temp < 0 || temp > 10);
	priority = temp;
	return priority;
}



//This function prompts the user for the distance of the hike.
bool show::set_live(){
	bool again = false;
	int temp = 0;
	do{
		cout << "Is this a live show or a movie? Enter 1 for live or 2 for movie" << endl;
		cin >> temp;
		cin.ignore(100 ,'\n');
		if(temp == 1){
			live = true;
			again = false;
		}
		else if(temp == 2){
			live = false;
			again = false;
		}
		else{
			cout << "Enter 1 or 2" << endl;
			again = true;
		}
	}while(again);
	return live;
}



//This function displays all information about the hike.
int show::display(){
	//convert length to hours.
	int minutes = length % 60;
	int hours = length/60;


	cout << "Show title: " << title << endl;
	cout << endl;
	cout << "Priority: " << priority << endl;
	cout << endl;
	if(live)
		cout << "This is a live show." << endl;
	else
		cout << "This is a movie." << endl;
	cout << endl;
	cout << "Length : " << hours << " hours and " << minutes << " minutes." << endl;
	cout << endl;
	my_date -> display();
	cout << "---------------------------------------------" << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////					DATE CLASS					////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//This class is used to store, display, and input a date.
date::date(){

}



//Copy constructor
date::date(date*const & source){
	is_am = source -> is_am;
	my_date[0] = source -> my_date[0];
	my_date[1] = source -> my_date[1];
	my_date[2] = source -> my_date[2];
	time[0] = source -> time[0];
	time[1] = source -> time[1];
}



//Destructor
date::~date(){

}



//This function displays the date and time.
int date::display(){
	cout << "Date: " << my_date[0] << "/" << my_date[1] << "/" << my_date[2] << endl;
	cout << "Time: "; 
	if(time[0] < 9)
		cout << "0";
	cout << time[0] << ":" ;
	if(time[1] < 9)
		cout << "0";
	cout << time[1] << " ";
	if(is_am)
		cout << "a.m." << endl;
	else
		cout << "p.m." << endl;
	return 1;
}



//This function allows calls the functions to input the date and time.
int date::input(){
	my_date[0] = input_month();
	my_date[1] = input_day();
	my_date[2] = input_year();
	input_time();
	return 1;
}



//This function prompts the user to input the time.
int date::input_time(){
	int temp = 0;
	do{
		cout << "Enter the hour. 1-12." << endl;
		cin >> temp;
		cin.ignore(100 , '\n');
		if(temp > 12 || temp < 1)
			cout << "Please enter 1 - 12" << endl;
	}while(temp > 12 || temp < 1);
	time[0] = temp;

	do{
		cout << "Enter the minute. 0 - 59." << endl;
		cin >> temp;
		cin.ignore(100 , '\n');
		if(temp < 0 || temp > 59)
			cout << "Please enter 0 - 59." << endl;
	}while(temp < 0 || temp > 59);
	time[1] = temp;

	do{
		cout << "Is the time AM or PM? enter 1 for AM or 2 for PM." << endl;
		cin >> temp;
		cin.ignore(100 , '\n');
		if(temp < 1 || temp > 2)
			cout << "Please enter 1 or 2" << endl;
	}while(temp < 1 || temp > 2);

	if(temp == 1)
		is_am = true;
	else
		is_am = false;
	return 1;
}



//This function prompts the user to input the month and returns the month.
int date::input_month(){
	int temp = 0;
	do{
		cout << "Enter the month. 1 - 12" << endl;
		cin >> temp;
		cin.ignore(100 ,'\n');
		if(temp < 0 || temp > 12)
			cout << "Please enter a valid month from 1 - 12." << endl;
	}while(temp < 0 || temp > 12);
	return temp;
}



//This function prompts the user to input the year and returns the year.
int date::input_year(){
	int temp = 0;
	cout << "Please enter the year." << endl;
	cin >> temp;
	cin.ignore(100 , '\n');
	return temp;
}



//This function promps the user to input the dat and returns the day.
int date::input_day(){
	int temp = 0;
	do{
		cout << "Please enter the day. 1-31" <<endl; 
		cin >> temp;
		cin.ignore(100 , '\n');
		if(temp < 0 || temp > 31)
			cout << "Please enter a valid day from 1 - 31." << endl;
	}while(temp < 0 || temp > 31);
	return temp;
}
