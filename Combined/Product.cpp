#include "pch.h"
Product::Product()
{
}
//Product::Product(int OID, std::string Prd_ID, int Q, bool MR, bool MSF, std::string Prt, int M, int D, int Y, int PT)
//{
//	Order_ID = OID;
//	Product_ID = Prd_ID;
//	Priority = Prt;
//	Quantity = Q;
//	SD_M = M;
//	SD_D = D;
//	SD_Y = Y;
//	Raw_Material = MR;
//	Machine_Shop_Finished = MSF;
//	Processing_Time = PT;
//}

Product::Product(int OID, int Q, bool MR, bool MSF, std::string Prt, int M, int D, int Y, int PT)
{
	Order_ID = OID;
	//Product_ID = Prd_ID;
	Priority = Prt;
	Quantity = Q;
	SD_M = M;
	SD_D = D;
	SD_Y = Y;
	Raw_Material = MR;
	Machine_Shop_Finished = MSF;
	Processing_Time = PT;
}

std::string Product::Get_Product_ID()
{
	return Product_ID;
}
unsigned int Product::Get_Order_ID()
{
	return Order_ID;
}
bool Product::Get_Product_Status()
{

	return Raw_Material*Machine_Shop_Finished;
}

unsigned int Product::Get_Quantity()
{
	return Quantity;
}

unsigned int Product::Get_Processing_Time()
{
	return Processing_Time;
}
std::ostream& operator <<(std::ostream& outp, Product Pdct)
{
	outp << "Product:	" << Pdct.Get_Product_ID() <<"	Quantity:	"<< Pdct.Get_Quantity() <<"		Ready?		" << Pdct.Get_Product_Status() << "		Processing Time:	" << Pdct.Get_Processing_Time() <<"	Shipping Date:	"<<Pdct.SD_D <<"-"<<Pdct.SD_M<<"-"<<Pdct.SD_Y<<std::endl;
	return outp;
}
