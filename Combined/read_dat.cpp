#include "pch.h"

void read_data(string orders_info, string orders_number, string qualify, int day, int month, int year) {



	Date Today;
	/*cout << "Please, Input Date\n" << "Day" << endl;
	cin >> Today.Day;
	cout << "\n Month" << endl;
	cin >> Today.Month;
	cout << "\n Year" << endl;
	cin >> Today.Year;
	cout << endl;*/

	Today.Day = day;
	Today.Month = month;
	Today.Year = year;

	ifstream Product_File;
	ifstream Order_File;
	string Product_Content;
	string Order_Content;
	vector<Product> Products;
	vector<int> Order_Numbers;
	int OID, Q;
	double PT; 
	bool MR, MSF;
	string PID, P;
	Date SD;
	int count1 = 0;
	int count2 = 0;
	Order_File.open(orders_number);
	if (Order_File.is_open())
	{
		while (getline(Order_File, Order_Content))
		{
			stringstream OrderStream(Order_Content);
			OrderStream >> OID;
			Order_Numbers.push_back(OID);

		}
	}
	else cerr << "File Error Code 1" << endl;
	//copy(Order_Numbers.begin(), Order_Numbers.end(), ostream_iterator<int>(cout, "\n"));

	groups = 5; 
	machines = 7;

	machine = new machine_info[machines + 1];
	group = new group_info[groups + 1];
	order = new order_info[Order_Numbers.size() + 1];
	orders = Order_Numbers.size(); 

	

	Product_File.open(orders_info);
	if (Product_File.is_open())
	{
		while (getline(Product_File, Product_Content))
		{
			
			replace(Product_Content.begin(), Product_Content.end(), ',', '	');
			stringstream ProductStream(Product_Content);
			/*ProductStream >> OID >> PID >> Q >> MR >> MSF >> P >> SD.Month >> SD.Day >> SD.Year >> PT;
			cout << OID << PID << Q << MR << MSF << P << SD.Month << SD.Day << SD.Year << PT << endl;*/

			ProductStream >> OID >> Q >> MR >> MSF >> P >> SD.Month >> SD.Day >> SD.Year >> PT;
			//cout << OID<< ","  << Q << "," << MR << "," << MSF << "," << P << "," << SD.Month << "," << SD.Day << "," << SD.Year << "," << PT << endl;
			Product P(OID, Q, MR, MSF, P, SD.Month, SD.Day, SD.Year, PT);
			//cout << P << endl;
			Products.push_back(P);

		}
	}

	else
	{
		cerr << "File Error Code2" << endl;
		EXIT_FAILURE;
	}
//	cout << "Input Complete" << endl;
	vector<int>::iterator itr1;
	vector<Product> Temp;
	vector<Order> Orders;
	vector<Order>::iterator itr2;

	//bool Compare_(Product)


	for (itr1 = Order_Numbers.begin()  ; itr1 != Order_Numbers.end(); itr1++)
	{
		Temp.clear();

		copy_if(Products.begin(), Products.end(), back_inserter(Temp),
			[&](auto i)
		{
			if (i.Get_Order_ID() == *itr1)
			{
				return true;
			}
			else return false;
		});

		//copy(Temp.begin(), Temp.end(), ostream_iterator<Product>(cout,"\n"));
		Orders.push_back(Order_Function(Temp, Today));
	}

	//copy(Orders.begin(), Orders.end(), ostream_iterator<Order>(cout, "\n"));
	//cout << "output";

	
	int i = 1; 
	for (itr2 = Orders.begin(); itr2 != Orders.end(); itr2++, i++) {

		order[i].number = (*itr2).Get_Order_ID();
		order[i].priority = (*itr2).Get_Priority();
		order[i].time = (*itr2).Get_Order_Processing_Time();
		order[i].time = order[i].time / 60; 
		order[i].deadline = (*itr2).Get_Deadline();
		if (order[i].deadline == 0) {
			order[i].deadline = 1; 
		}
		

		order[i].group = 0; 
	}
		




	
	ifstream myfile(qualify);
	//cout << "File name is: " << filename << endl;
	string line; 
	char delimiter; 
	getline(myfile, line);
	stringstream iss(line);
	for (int o = 1; o <= orders; o++) {
		getline(myfile, line);
		stringstream iss(line);
		int num;
		while (!iss.eof()) {
			iss >> num;
			if (num == 4) num = 2;
			if (num == 7) num = 3;
			if (num == 10) num = 4;
			if (num == 12) num = 5;
			order[o].quali.push_back(num);
			iss >> delimiter;
		}
		order[o].quali.pop_back(); 
		int max = 5;
		int min = 1;
		int randNum = rand() % (max - min + 1) + min;
		order[o].status = randNum;
		order[o].flag = 0; 
		
	}

	

	for (int i = 1; i <= 3; i++) {
		group[1].cells.push_back(i);
	}

	for (int i = 4; i <= 6; i++) {
		group[2].cells.push_back(i);
	}

	for (int i = 7; i <= 9; i++) {
		group[3].cells.push_back(i);
	}

	for (int i = 10; i <= 11; i++) {
		group[4].cells.push_back(i);
	}

	for (int i = 12; i <= 13; i++) {
		group[5].cells.push_back(i);
	}

	for (int i = 1; i <= groups; i++) {
		int cap = 7;
		
		group[i].capacity = cap*group[i].cells.size();
		//cout << group[i].capacity << endl; 
		
		for (int j = 0; j <= days; j++) {

			group[i].avai_time.push_back(group[i].capacity);
		}
	}

	for (int j = 1; j <= machines; j++) {
		machine[j].number_of_machine = 5; 
		machine[j].capacity = 7; 
		machine[j].capacity = machine[j].number_of_machine * machine[j].capacity; 
		for (int i = 0; i <= days; i++) {

			machine[j].avai_time.push_back(machine[j].capacity);
		}
	}

	group[1].number = 1;
	group[2].number = 4;
	group[3].number = 7;
	group[4].number = 10;
	group[5].number = 12; 

	//sort(order.begin(), order.end(), compare); 
	//std::sort(order.begin(), order.end());
}