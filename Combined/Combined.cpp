// Combined.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int orders, days, groups;


order_info * order;
group_info * group;
vector <machine> machines;
vector <sequence> sequences;
int main()
{
	int day, month, year; 

	//large instance
	string order_input = "Order_info.csv"; 
	string order_number = "Orders.csv";
	string qualify = "Quali.csv"; 

	//small instance
	/*string order_input = "Order_info_1.csv";
	string order_number = "Orders_1.csv";
	string qualify = "Quali_1.csv";*/


	
	cout << "Please input day, month and year" << endl; 
	cin >> day >> month >> year; 
	cout << "Please enter number of days to schedule " << endl; 
	cin >> days; 
	//number_of_days = 20; 
	read_data(order_input, order_number, qualify, day, month, year);
	
	cout << endl; 

	if (best_fit2()) {
		//improve_solution(); 
		print_a_schedule(day, month, year); 
	}
	else cout << "Error: No avai_time Order." << endl; 

	char x; 
	cout << "Exit ?"; 
	cin >> x; 

	//order->quali.clear();
	delete[] order;
	delete[] group;


	


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

bool compare_groups(int a, int b)
{


	return group[a].current_useage < group[b].current_useage;


}



void print_orders() {
	for (int o = 1; o <= orders; o++) {
		cout << order[o].number << " " << order[o].deadline << " " << order[o].time << " " << group[order[o].group].number
			<< " " << group[order[o].group].current_useage << endl;
	}

}


bool compare_status(int a, int b) {
	return (order[a].flag > order[b].flag || (order[a].status < order[b].status && order[a].flag == order[b].flag));
}

void assign(int a, int g) {

	order[a].group = g;
	group[g].current_useage += order[a].time;
	group[g].makespan = ceil(group[g].current_useage / group[g].capacity); 
	order[a].day = group[g].makespan; 
	cout << order[a].day << endl; 
	//order[a].group = group[g]; 
	
	//cout << "order " << a << " "<< g.number << " " << g.current_useage << endl;
	//if (order[a].flag == 1) {
	//	order[a].day = day;
	//	order[a].group = asembly_group;
	//	double value = order[a].time; 
	//	//cout << d << " " << group[asembly_group].avai_time[d]; 
	//	for (value = order[a].time; value >= 0;  day++) {
	//		double temp = asembly_group.avai_time[day];
	//		if (asembly_group.avai_time[day] - value < 0) {
	//			
	//			asembly_group.avai_time[day] = 0;
	//		}
	//		else group[asembly_group].avai_time[day] = asembly_group.avai_time[day] - value;
	//		group[asembly_group].makespan = day; 
	//		value -= temp; 
	//	}
	//	/*while (value >= 0) {
	//		value  -= group[asembly_group].avai_time[day];
	//		group[asembly_group].avai_time[day] = 0;
	//		day++; 
	//	}*/

	//}

	//else {
	//	order[a].day = day;
	//	group[asembly_group].makespan = day; 
	//	order[a].group = asembly_group;
	//	group[asembly_group].avai_time[day] -= order[a].time;
	//}

}
