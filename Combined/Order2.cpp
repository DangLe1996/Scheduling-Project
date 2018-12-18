#include "pch.h"
Order::Order()
{
}

Order::Order(int OID, int DL, bool S, int P, int OPT)
{
	Order_ID=OID;
	Deadline=DL;
	Status= S;
	Priority = P;
	Order_Processing_Time = OPT;
}

int Order::Get_Order_ID()
{
	return Order_ID;
}

unsigned int Order::Get_Deadline()
{
	return Deadline;
}
bool Order::Get_Status()
{
	return Status;
}
unsigned int Order::Get_Priority()
{
	return Priority;
}

int Order::Get_Order_Processing_Time()
{
	return Order_Processing_Time;
}

std::ostream & operator<<(std::ostream& outo, Order O)
{
	outo << "Order ID:	" << O.Get_Order_ID() << "	Deadline:	" << O.Get_Deadline() 
		<< "	Status:		" << O.Get_Status() << "	Priority:	" << O.Get_Priority() 
		<< "	Order Processing Time:	" << O.Get_Order_Processing_Time() << std::endl;
	return outo;
}