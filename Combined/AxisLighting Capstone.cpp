#include "pch.h"







int main(int argc, const char * argv[])
{

	Date Today;
	/*cout << "Please, Input Date\n" << "Day" << endl;
	cin >> Today.Day;
	cout << "\n Month" << endl;
	cin >> Today.Month;
	cout << "\n Year" << endl;
	cin >> Today.Year;
	cout << endl;*/

	Today.Day = 11;
	Today.Month = 10;
	Today.Year = 2018; 

	ifstream Product_File;
	ifstream Order_File;
	string Product_Content;
	string Order_Content;
	vector<Product> Products;
	vector<int> Order_Numbers;
	int OID, Q, PT;
	bool MR, MSF;
	string PID, P;
	Date SD;
	int count1 = 0;
	int count2 = 0;
	Order_File.open("OrderInput.csv");
	if (Order_File.is_open())
	{
		while (getline(Order_File, Order_Content))
		{
			stringstream OrderStream(Order_Content);
			OrderStream >> OID;
			//cout << OID << endl;
			Order_Numbers.push_back(OID);

		}
	}
	else cerr << "File Error Code 1" << endl;
	copy(Order_Numbers.begin(), Order_Numbers.end(), ostream_iterator<int>(cout, "\n"));

	Product_File.open("InputsFinal.csv");
	if (Product_File.is_open())
	{
		while (getline(Product_File, Product_Content))
		{
			replace(Product_Content.begin(), Product_Content.end(), ',', '	');
			stringstream ProductStream(Product_Content);
			ProductStream >> OID >> PID >> Q >> MR >> MSF >> P >> SD.Month >> SD.Day >> SD.Year >> PT;
			//cout << OID << PID << Q << MR << MSF << P << SD.Month << SD.Day << SD.year << PT << endl;
			Product P(OID, PID, Q, MR, MSF, P, SD.Month, SD.Day, SD.Year, PT);
			cout << P << endl;
			Products.push_back(P);

		}
	}

	else
	{
		cerr << "File Error Code2" << endl;
		EXIT_FAILURE;
	}
	cout << "Input Complete" << endl;
	vector<int>::iterator itr1;
	vector<Product> Temp;
	vector<Order> Orders;
	vector<Order>::iterator itr2; 

	//bool Compare_(Product)


	for (itr1 = Order_Numbers.begin(); itr1 != Order_Numbers.end(); ++itr1)
	{
		Temp.clear();

		copy_if(Products.begin(), Products.end(), back_inserter(Temp),
			[&](auto i)
		{
			if (i.Get_Order_ID()==*itr1)
			{
				return true;
			}
			else return false;
		});

		//copy(Temp.begin(), Temp.end(), ostream_iterator<Product>(cout,"\n"));
		Orders.push_back(Order_Function(Temp, Today));
	}

	//copy(Orders.begin(), Orders.end(), ostream_iterator<Order>(cout, "\n"));
	cout << "output"; 

	for (itr2 = Orders.begin(); itr2 != Orders.end(); itr2++) {
		cout << (*itr2).Get_Deadline(); 
	}

	
	
	

	EXIT_SUCCESS;

}