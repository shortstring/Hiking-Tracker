//Ashton Smith CS202 Program 2
//dll.cpp
//This .cpp file contains functions for managing the DLL and nodes.
#include "dll.h" 
using namespace std;
const int SIZE = 5;
const int MAX = 100; 
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////					LIST CLASS					////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
list::list(){
	head = NULL;

}



//Destructor
list::~list(){
	remove_all(head);
}

//copy constructor
list::list(const list & source){
copy_all(source.head, head);

}


//copies the entire list
void list::copy_all(node * source, node *& dest){
	if(!source)
		return;
	else{
		dest = new node(*source);
		if(!this -> head){
			this -> head = dest;
		}
		copy_all(source -> go_next(), dest -> go_next());
	}
	if(dest -> go_next()){
		dest -> go_next() -> connect_previous(head);
	}
}



//This function is the wrapper function to display the entire list.
int list::display_all(){
	if(!head){
		cout << "There is nothing to display." << endl;
		return 0;
	}
	else
		return display_all(head);

}



//This function is the wrapper function to display the entire list.
int list::display_all(node * head){
	if(!head)

		return 0;
	else
		head -> display(); //Display the node 

	display_all(head -> go_next()); //Recursive call
	return 1;
}



//Wrapper function to remove an activity by name.
int list::remove(){
	if(!head){
		cout << "There is nothing to remove" << endl;
		return 0;
	}
	else
	{
		char * to_remove = new char[MAX + 1];
		cout << "Enter the name of the activity to remove: " << endl;
		cin.get(to_remove, MAX, '\n');
		cin.ignore(100, '\n');
		remove(to_remove, head);
		delete[] to_remove;
	}
}	



//Recursive function to remove an activity by name.
int list::remove(char * to_remove, node *& head){
if(!head)
	return 0;
if(head -> search_for_name(to_remove))
	return 1;
else
	return remove(to_remove, head -> go_next());
}



//This function displays all nodes with a specific priority, This is the weapper function.
int list::display_priority(){
	if(!head){
		cout << "There is nothing to display." << endl;
		return 0;
	}
	else{
		int temp;
		cout << "What priority would you like to display? Enter a number. " << endl;	
		cin >> temp; cin.ignore(100 , '\n');
		return display_priority(temp, head);

	}
}



//This function recursivley searches for a specific priority and then displays it.
int list::display_priority(int priority, node * head){
	if(!head)
		return 0;
	else if(head -> get_priority() == priority){
		head -> display();
		return 1;
	}
	else
		return display_priority(priority, head -> go_next());

}



//This function function is the wrapper function to add to the list.
int list::add(activity *& to_add){
	add(head, to_add);
}



//This function adds to the doubly linked list. Then it calls the function to add to the array. The argument is the node pointer to
//recursivley call and the activity pointer to add.
int list::add(node *& head, activity *& to_add){
	node * temp;
	if(!head){
		head = new node;
		if(!this -> head)
			this -> head = head;
		head -> add(to_add);
		head -> go_next() = NULL;
		return 1;
	}
	if(head -> get_priority() == to_add -> get_priority()){
		if(!head -> add(to_add)){
			cout << "Failed to add activity. That priority is full, enter a different priority. " << endl;
			to_add -> set_priority();
			add(this -> head, to_add);
			return 0;
		}
	}
	else if( head -> get_priority() < to_add -> get_priority())
	{	
		temp = new node;
		temp -> go_next() = head;
		temp -> add(to_add);
		if(head == this -> head){
			this -> head = temp;
		}
		if(head -> go_previous())
			head -> go_previous() -> connect_next(temp);
	}
	else
		add(head -> go_next(), to_add); //go next	
	if(head -> go_next())
		head -> go_next() -> connect_previous(head);
	return 1;
}



//Removes all nodes.
void list::remove_all(node *& head){
	if(!head)
		return;
	else
		remove_all(head -> go_next());

	delete head;
	head = NULL;

}



////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////					NODE CLASS					////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//Constructor.
node::node(){
	my_activities = new activity*[SIZE];
	int temp = 0;
	set_array_null(temp);
	priority = 0;
}



//This is a helper function to set each index to NULL.
void node::set_array_null(int & size){
	if(size == SIZE)
		return;
	my_activities[size] = NULL;
	++size;
	return set_array_null(size);
}



//Copy constructor
node::node(const node *& source){
	int size = 0;
	my_activities = new activity*[SIZE];
	copy_array(size, source);

}



//Copy all
void node::copy_array(int & size, const node *& source){
	if(size == SIZE)
		return;
	if(source -> my_activities[size])
	my_activities[size] = new activity(*source -> my_activities[size]);
	else 
	my_activities[size] = NULL;
	++size;
	return copy_array(size, source);
}



//Destructor
node::~node(){
	int temp = 0;
	remove_all_array(temp);
	delete[] my_activities;
}



//This is a helper function to set each index to NULL.
void node::remove_all_array(int & size){
	if(size == SIZE)
		return;
	if(my_activities[size])
		delete my_activities[size];
	my_activities[size] = NULL;
	++size;
	return remove_all_array(size);
}



//This function is the wrapper function to add an activity to the array.
int node::add(activity *& to_add){
	priority = to_add -> get_priority();
	int temp = 0;
	return add(temp, to_add);

}



//This function returns the priority. Used for sorting.
int node::get_priority(){
	return priority;
}



//This function adds an activity to the array.
int node::add(int & size, activity *& to_add){
	char * temp;
	if(size == SIZE - 1)
		return 0;
	if(!my_activities[size]){
		my_activities[size] = to_add;
		arr_sort();
		arr_sort();
		arr_sort();
		arr_sort();
		arr_sort();
		return 1;
	}
	++size;
	return add(size, to_add);
}



//This function returns the next pointer.
node *& node::go_next(){
	return next;
}



//This function returns the previous pointer.
node *& node::go_previous(){
	return previous;
}



//This function sets the argument to the previous pointer.
void node::connect_previous(node * to_connect){
	previous = to_connect;
}



//This function sets the argument to the next pointer.
void node::connect_next(node * to_connect){
	next = to_connect;
}



//Warpper function to display each array index.
int node::display(){
	int temp = 0;
	display(temp);
}



//This function displays all activities in the array.
int node::display(int & size){
	if(size == SIZE)
		return 1;
	else if(my_activities[size])
		my_activities[size] -> display();
	++size;
	return display(size);

}



//This is the wrapper function to remove a given name.
int node::search_for_name(char * name){
	int temp = 0;
	search_for_name(name, temp);
}



//This is the recursive function to remove a given name.
int node::search_for_name(char * name, int & num){
	if(num == SIZE)
		return 0;
	if(my_activities[num] && !my_activities[num] -> is_match(name)){
		delete my_activities[num];
		my_activities[num] = NULL;
		return 1;
	}
	else
	{
		++num;
		return search_for_name(name, num);
	}

}



//rray sorting wrapper function
int node::arr_sort(){
	int temp = 0;
	return arr_sort(temp);
}



//This function is used to check if the array is sorted by alpha.
int node::arr_sort(int num){
	if(num == SIZE - 2)
		return 0;
	if(my_activities[num] && my_activities[num + 1]){
		activity * temp2 = my_activities[num+1];
		if(!my_activities[num] -> compare_title(temp2))
		{
			activity * temp = my_activities[num];
			my_activities[num] = my_activities[num + 1];
			my_activities[num +1] = temp;
		}
		++num;
		arr_sort(num);
	}else{
		++num;
		arr_sort(num);
	}
	return 1;
}
