#pragma once



//
//#include "targetver.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>

//#include <ilcplex/ilocplex.h>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <set>
#include <iostream>
#include <fstream>
#include <random>
#include <string>




using namespace std;

extern int orders, days, groups;



struct group_info {
	int number; 
	int capacity;
	int numb_cell;
	int makespan; 
	double current_useage;
	vector<double> avai_time;
	vector<int> cells;

};

struct machine {
	string name; 
	int number; 
	int capacity;
	int number_of_machine;
	int p_time; 
	machine(string n, int c, int m, int num , int p) {
		capacity = c; 
		name = n; 
		number_of_machine = m; 
		capacity = c * m; 
		number = num; 
		p_time = p; 
	}
};
struct sequence {
	vector<machine> m; 
	int number; 
	sequence(vector<machine> v1, int n) {
		m = v1; 
		number = n; 
	}
};
struct sub_orders {
	int seq_number;
	sub_orders(int n) {
		seq_number = n; 
	}
	int finish_time; 
};
struct order_info {
	int number;
	int group;
	int day;
	double time;
	int deadline;
	vector<int> quali;
	vector<sub_orders> sub_order; 
	int sequence; 
	int priority;
	int status; 
	int flag; 
};


void init_machines(); 

bool compare_deadline(order_info a, order_info b);
bool compare_status(int a, int b);
bool compare_number(order_info a, order_info b);
extern order_info * order;
extern vector <machine> machines;
extern vector <sequence> sequences;

extern group_info * group;
void best_fit(int o);
void solve_MIP();
void read_data(string orders_info, string orders_number, string qualify, int day, int month, int year);
void dynamic_prog();
void assign(int a, int g);
int can_fit(order_info o, group_info g);
int max(int a, int b);
int best_fit2(); 
void improve_solution(); 
void print_a_schedule(int day, int month, int year);
bool compare_groups(int a, int b);
void print_orders();
 