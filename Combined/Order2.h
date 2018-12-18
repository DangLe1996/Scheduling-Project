#ifndef  Order2_h
#define Order2_h
#include "pch.h"
class Order
{
private:
	int Order_ID;
	int Deadline;
	bool Status;
	int Priority;
	int Order_Processing_Time;
public:
	Order();
	Order(int OID, int DL, bool S, int P, int OPT);
		int Get_Order_ID();
		unsigned int Get_Deadline();
		bool Get_Status();
		unsigned int Get_Priority();
		int Get_Order_Processing_Time();
		friend std::ostream& operator <<(std::ostream& outo, Order O);
		//~Order(){}
};
#endif