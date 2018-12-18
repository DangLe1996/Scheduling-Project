// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

int orders, days, groups;
int cells; 

 order_info * order;
 group_info * group;


int main(int argc, char *argv[])
{
	cells = 13; 
	/* for (int o = 1; o <= orders; o++) {
		 int max = 7;
		 int min = 2;
		 int randNum = rand() % (max - min + 1) + min;
		 order[o].time = randNum; 
		 max = groups; 
		 min = 0; 
		 int randNum = rand() % (max - min + 1) + min;
		 order[o].quali.push_back(randNum); 
	 }*/
	
	 read_data(); 

	 /*for (int o = 1; o <= orders; o++) {
		 cout << endl; 
		 cout << order[o].number << " " << order[o].deadline << " " << order[o].time << endl; 
		 for (int i = 0; i < order[o].quali.size(); i++) {
			 cout << order[o].quali[i] << " "; 
		 }
		 cout << endl; 
	 }
*/

	//solve_MIP(); 
	// dynamic_prog(); 
	 
	best_fit();
	
	

	order->quali.clear(); 
	delete[] order; 
	delete[] group; 

	cin.get();
	return 0;
}

bool compare_deadline(order_info a, order_info b)
{


	return a.deadline < b.deadline;


}

bool compare_number(order_info a, order_info b)
{


	return a.number < b.number;


}




