//Ashton Smith CS202 Program 2
//activity.h
//This .h file contains all class defintions for activity related classes.
#include <iostream>
#include <cstring>
#include <cctype>
class date;



class activity
{
	public:
		activity();
		activity(const activity & source);
		virtual ~activity();
		int add();
		bool compare_title(activity *);
		bool is_match(char *);
		virtual int get_priority();
		virtual double set_distance();
		virtual double set_cost();	
		virtual bool set_live();	
		virtual int display();
		virtual int set_date();
		virtual int set_length();
		virtual int set_priority();
	
	protected:
		char * title;
		date * my_date;


};



class hiking: public activity
{
	public:
		hiking();
		hiking(const hiking &);
		~hiking();
		int display();
		int set_date();
		int set_length();
		int set_priority();
		double set_distance();
		int get_priority();
	protected:
		double distance;
		int length;//Length in minutes
		int priority; //Priority 1 - 10 higher more important.
		bool solo; //Activity done alone or with others.
		int time; //Time in minutes to do activity.
};



class dining: public activity
{
	public:
		dining();
		dining(const dining &);
		~dining();
		int display();
		int set_date();
		int set_length();
		int set_priority();
		double set_cost();
		int get_priority();
	protected:
		double cost;
		int length;//Length in minutes
		int priority; //Priority 1 - 10 higher more important.
		bool solo; //Activity done alone or with others.
		int time; //Time in minutes to do activity.
};



class show: public activity
{
	public:
		show();
		show(const show &);
		~show();
		int display();
		int set_date();
		int set_length();
		int set_priority();
		bool set_live();
		int get_priority();
	protected:
		bool live; //Is the show live or a movie
		int length;//Length in minutes
		int priority; //Priority 1 - 10 higher more important.
		bool solo; //Activity done alone or with others.
		int time; //Time in minutes to do activity.
};



class date
{
	public:
		date();
		date(date*const &);
		~date();
		int display();
		int input();
		int input_month();
		int input_year();
		int input_day();
		int input_time();
	private:
		bool is_am;
		int time[2];
		int my_date[3];
};
