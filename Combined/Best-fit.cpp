#include "pch.h"

int best_fit(int number_of_days) {


	vector<int> seed;
	int flag = 0; 
	for (int o = 1; o <= orders; o++) {
		if (order[o].status == 1 && order[o].deadline <= number_of_days) {
			for (int g : order[o].quali) {
				if (order[o].time <= group[g].capacity) {
					seed.push_back(o);
					flag = 1;
				}
				else {
					cout << order[o].number << " has more time than capacity" << endl;
					break; 
				}
			}
		}
	}
	if (flag == 0) return 0; 

	//sort(order + 1, order + orders, compare_deadline);

	int best_sol = INT_MAX;
	int max_day = 0;

	

	auto rng = std::default_random_engine{};


	int day = 1;
	//for (int iter = 0; iter < 10000; iter++) {
	while (!seed.empty()) {

		for (int o : seed) {

			int min = INT_MAX;
			int max = 0;
			int index_job;
			int index_group;

			std::shuffle(order[o].quali.begin(), order[o].quali.end(), rng);


			if (order[o].priority == 1 && day == order[o].deadline - 1) {
				seed.erase(remove(seed.begin(), seed.end(), o), seed.end());
			}
			else if (order[o].priority == 2 && day >= order[o].deadline - 2) {
				seed.erase(remove(seed.begin(), seed.end(), o), seed.end());
			}
			else if (order[o].priority == 3 && day >= order[o].deadline - 5) {
				seed.erase(remove(seed.begin(), seed.end(), o), seed.end());
			}
			else continue;
			

			for (int g : order[o].quali) {
				int value = group[g].avai_time - order[o].time;

				if (value >= 0 && value < min) {
					min = value;
					index_job = g;

				}

				if (min == INT_MAX) {
					index_job = order[o].quali[0];
					group[index_job].current_day++;
					group[index_job].avai_time = group[index_job].capacity;
				}

				
			}

			group[index_job].current_day = day;
			order[o].group = group[index_job].number;
			order[o].day = group[index_job].current_day;
			group[index_job].avai_time -= order[o].time;
			
		}
		//if (max_day < best_sol) best_sol = max_day;
		day++; 
	}
	//cout << endl; 
	//cout << "max day is " << day << endl; 
	
		sort(order + 1, order + orders, compare_number);
		
	
		
		return 1; 
	

	
}