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

extern int orders, days, groups, machines;



struct group_info {
	int number; 
	int capacity;
	int numb_cell;
	int makespan; 
	vector<double> avai_time;
	vector<int> cells;

};

struct machine_info {
	string name; 
	vector<double> avai_time;
	int capacity;
	int number_of_machine;

};

struct order_info {
	int number;
	int group;
	int day;
	double time;
	int deadline;
	vector<int> quali;
	vector<int> m_seq;
	int priority;
	int status; 
	int flag; 
};


bool compare_deadline(order_info a, order_info b);
bool compare_status(int a, int b);
bool compare_number(order_info a, order_info b);
extern order_info * order;
extern machine_info * machine;
extern group_info * group;
void best_fit(int o);
void solve_MIP();
void read_data(string orders_info, string orders_number, string qualify, int day, int month, int year);
void dynamic_prog();
void assign(int a, int day, int asembly_group);
int can_fit(order_info o, group_info g);
int max(int a, int b);
int best_fit2(); 
void improve_solution(); 
void print_a_schedule(int day, int month, int year);
