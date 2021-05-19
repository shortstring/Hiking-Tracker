//Ashton Smith CS202 Program 2
//dll.h
//This .h file is used for the class defintions of the Doubly linked list and node class.
#include "activity.h"
class node;



//Doubly linked list
class list
{	
	public:
		list();
		list(const list & source);
		~list();
		int display_all();
		int display_priority();
		int add(activity *& to_add);
		int remove();
	private:
		void copy_all(node * head, node *& dest);
		int remove(char * to_remove, node *& head);	
		int display_priority(int priority, node * head);
		void remove_all(node *& head);
		int display_all(node * head);
		int add(node *& head, activity *& to_add);
		node * head;
};	


//DLL node
class node
{
	public:
		node();
		node(const node *& source);
		~node();
		int add(activity *& to_add);
		node *& go_next();
		node *& go_previous();
		int search_for_name(char * name);
		int arr_sort();
		int get_priority();
		int display();
		void connect_previous(node *);
		void connect_next(node *);
		int retrieve();
	private:	
		void copy_array(int & size, const node *& source);
		int search_for_name(char * name, int & num);
		void remove_all_array(int &);
		int arr_sort(int num);
		int display(int & size);
		int sort();
		int add(int & size, activity *& to_add);
		void set_array_null(int &);
		int priority;
		activity ** my_activities;
		node * next;
		node * previous;
};
