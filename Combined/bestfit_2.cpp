#include "pch.h"
int best_fit2() {

	int k;
	vector<int> seed;
	int flag = 0;
	for (int o = 1; o <= orders; o++) {
		//check if order is within schedule horizon and available to schedule
		if ( order[o].deadline <= days && order[o].status > 0) {
			//check if order status is "Assembly started", the assign to the first qualified group
			//assuming that only 1 group qualified to assemble it. 
			if (order[o].status == 1) {
				k =order[o].quali[0];
				assign(o, k);
				

			}
			else {
				seed.push_back(o);
			}
			flag = 1;
		for (int g : order[o].quali) {
				if (order[o].time <= group[g].capacity) {
					
				}
				else {
					//check if there is an order that takes more than 1 day to assemble. 
					cout << order[o].number << " has more time than capacity" << endl;
					order[o].flag = 1; 
					break; 
				}
			}
			
		}
	}
	if (flag == 0) return 0;
	
	//sort the order by status, from 2 to 5. 
	sort(seed.begin(), seed.end(), compare_status);
	//cout << endl; 
	
	int best_sol = INT_MAX;
	int max_day = 0;


	int day = 1;


	for (int o : seed) {
		//sort the qualified group for the order by current useage. Assign to the lowest one. 
		sort(order[o].quali.begin(), order[o].quali.end(), compare_groups);
		k = order[o].quali[0];
		assign(o, k); 

	}


	//print_orders(); 
	//
	//for (int g = 1; g <= groups; g++) {
	//	cout << g << " " << group[g].current_useage << " " << group[g].makespan<<  endl;
	//}





	return 1;



}


void print_a_schedule(int day, int month, int year) {
	ofstream output("output.csv");

	cout << "order " << " " << "group" << " " << "day " << " " << "deadline" << " " << "priority" << endl;
	output << "order ," << " " << "group," << " " << "day ," << " " << "deadline," << "priority," << "status" <<endl;
	for (int o = 1; o <= orders; o++) {
		if (order[o].group > 0) {
			string date;
			ostringstream schedule_date, duedate;
			schedule_date << order[o].day + day - 1 << " / " << month << " / " << year;
			duedate << order[o].deadline + day - 1 << " / " << month << " / " << year;
			/*if (order[o].day - 1 + day > 30) {
			date = { } +"/" + month + 1 + '/' + year;
			}
			else date = order[o].day - 1 + day + "/" + month  + '/' + year;*/

			cout << order[o].number << "\t " << order[o].group << " \t" << schedule_date.str() << "\t " << duedate.str()
				<< "\t " << order[o].priority << " " << order[o].status << " " << order[o].time << endl;
			output << order[o].number << ", " << order[o].group << " ," << schedule_date.str() << ", " 
				<< duedate.str() << ", " << order[o].priority << ", " << order[o].status << endl;
		}

	}
	cout << endl;
	for (int g = 1; g <= groups; g++) {
		cout << "group " << g << endl;
		//for (int d = 1; d <= group[g].makespan; d++) {
			cout << group[g].current_useage << endl;
		//}
		cout << endl;
	}

}






//void best_fit(int o) {
//
//	
//	int min = INT_MAX;
//	int max = 0;
//	int index_job;
//	int best_group;
//	int best_day; 
//	auto rng = std::default_random_engine{};
//
//	std::shuffle(order[o].quali.begin(), order[o].quali.end(), rng);
//	/*for (int d = 1; d <= days; d++) {
//		for (int g : order[o].quali) {
//
//			int value = group[g].avai_time[d] - order[o].time;
//			if (value > 0 && value < min) {
//				min = value;
//				best_day = d;
//				best_group = g;
//				assign(o, best_day, best_group);
//				return; 
//			}
//		}
//
//	}*/
//	/*if(min != INT_MAX)
//	assign(o, best_day, best_group); 
//	else cout << "Order " << o << " cannot be assigned due to capacity"; */
//
//}
//
//void improve_solution() {
//	/*for (int o = 1; o <= orders; o++) {
//		bool gotoMainLoop = false;
//		if (order[o].group > 0 && order[o].status != 1) {
//			for (int d = 1; d < order[d].day && !gotoMainLoop; d++) {
//				for (int g : order[o].quali) {
//					if (group[g].avai_time[d] >= order[o].time) {
//						assign(o, d, g); 
//						gotoMainLoop = true;
//						break; 
//					}
//				}
//			}
//		}
//
//	}
//*/
//
//
//
//}


















//for (int o : seed) {
//	cout << " " << o << " " << order[o].number << " " << order[o].priority << " " << order[o].flag << " " << order[o].status << endl; 
//	if (order[o].status == 1 && order[o].flag == 1) {
//		switch (order[o].priority)
//		{
//		case 1: assign(o, order[o].deadline , order[o].group);
//			break;
//		case 2: assign(o, order[o].deadline, order[o].group);
//			break; 
//		case 3: assign(o, order[o].deadline + 1, order[o].group);
//			break; 

//		default:
//			break;
//		}
//	}
//	else {
//		if (order[o].status == 1) {
//			//cout << o << " " << order[o].group;
//			assign(o, 1, order[o].group);
//			//seed.erase(remove(seed.begin(), seed.end(), o), seed.end());
//		}
//		else if (order[o].flag == 1) { //flag = 1 means assembly takes more than 1 day
//			//seed.erase(remove(seed.begin(), seed.end(), o), seed.end());
//			switch (order[o].priority)
//			{
//			case 1: assign(o, order[o].deadline, order[o].quali[0]);
//				break; 
//			case 2: assign(o, order[o].deadline, order[o].quali[0]);
//				break;
//			case 3: assign(o, order[o].deadline + 1, order[o].quali[0]);
//				break; 

//			default:
//				break;
//			}

//		}
//		else if (order[o].status != 1 && order[o].flag != 1) {

//			best_fit(o);
//		}
//	}

//}


//sort(order + 1, order + orders, compare_number);

