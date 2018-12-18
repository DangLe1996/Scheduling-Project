#ifndef  Product_h
#define Product_h
#include "pch.h"
class Product
{
private:
	unsigned int Order_ID;
	std::string Product_ID;
	unsigned int Quantity;
	bool Raw_Material;
	bool Machine_Shop_Finished;
	unsigned int Processing_Time;
public:
	Product();
	std::string Priority;
	int SD_M;
	int SD_D;
	int SD_Y;
	Product(int OID, int Q, bool MR, bool MSF, std::string Prt, int M, int D, int Y, int PT);
	//Product(int OID, std::string Prd_ID, int Q, bool MR, bool MSF, std::string Prt, int M, int D, int Y, int PT);
	unsigned int Get_Order_ID();
	bool Get_Product_Status();
	unsigned int Get_Quantity() ;
	std::string Get_Product_ID() ;
	unsigned int Get_Processing_Time();
	friend std::ostream& operator <<(std::ostream& outp, Product Pdct);
	//~Product(){}
};
#endif