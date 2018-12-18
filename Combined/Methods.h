#ifndef  Methods_h
#define Methods_h
#include "pch.h"
#include "Product.h"
#include "Order2.h"
struct Date
{
	int Month;
	int Day;
	int Year;
};
int P_string_To_int(std::string& Priority);
int Dl_Comp(int D, int M, int Y, Date T);
Order Order_Function(std::vector<Product> P, Date T);
inline int P_string_To_int(std::string& Pr)
{
	if (Pr == "HIGHPRIORITY")
	{
		return 1;
	}
	else if (Pr == "PRIORITY")
	{
		return 2;
	}
	else
		return 3;
}

inline int Dl_Comp(int D, int M, int Y, Date T)
{
	int Del_Y = Y - T.Year;
	int Del_M = Del_Y * 12 + M - T.Month;
	int Del_D = Del_M * 30 + D - T.Day;
	return Del_D;
}
inline Order Order_Function(std::vector<Product> P, Date T)
{
	std::vector<Product>::iterator itr;
	int TPT = 0;
	int Dl = 0;
	int OID=0;
	int S=0;
	int Prt=3;
	for (itr = P.begin(); itr != P.end(); ++itr)
	{
		OID = itr->Get_Order_ID();
		TPT += (itr->Get_Processing_Time())*(itr->Get_Quantity());
		Dl = Dl_Comp(itr->SD_D, itr->SD_M, itr->SD_Y, T);
		S += itr->Get_Product_Status();
		Prt = P_string_To_int(itr->Priority);
	}
	bool n;
	if (S != P.size())
	{
		n=false;
	}
	else n = true;

	return Order(OID, Dl, n, Prt, TPT);
}
#endif // !

