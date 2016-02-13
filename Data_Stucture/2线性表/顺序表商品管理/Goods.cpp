#include "Goods.h"
#include <time.h> 
using namespace std;

Goods::Goods()
{
	
}

Goods::Goods(long int goods_ID,string goods_name,int current_stock,int min_stock)
{
	this->goods_ID = goods_ID;
	this->goods_name = goods_name;
	this->current_stock = current_stock; 
	this->min_stock = min_stock;
}

Goods::~Goods()
{
}

//重载输入输出操作符
ostream & operator << (ostream & os,Goods & goods)
{
	os<<"ID:"<<"\t"<<"Name:"<<"\t"<<"Current Stock:"<<"\t"<<"Stock:"<<"\n"<<endl;
	os<< goods.goods_ID <<"\t"<< goods.goods_name <<"\t"<< goods.current_stock <<"\t"<< goods.min_stock <<"\n"<<endl;
	return os;
}

istream & operator >> (istream & is,Goods & goods)
{
	cout <<"ID:"<<"\t"<<"Name:"<<"\t"<<"Current Stock:"<<"\t"<<"Stock:"<<"\n"<<endl;
	is >> goods.goods_ID >> goods.goods_name >> goods.current_stock >> goods.min_stock;
	return is;
}

bool operator<(Goods & goods1, Goods & goods2)
{
	if(goods1.goods_ID < goods2.goods_ID)
		return true;
	return false;
}

bool operator>(Goods & goods1, Goods & goods2)
{
	if(goods1.goods_ID > goods2.goods_ID)
		return true;
	return false;
}

bool operator==(Goods & goods1, Goods & goods2)
{
	if(goods1.goods_ID > goods2.goods_ID)
		return true;
	return false;
}
