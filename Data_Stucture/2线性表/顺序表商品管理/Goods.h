#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <string>
using namespace std;

class Goods
{
public:
	//重载输入输出操作符
	friend ostream & operator<<(ostream & os,Goods & goods);
	friend istream & operator>>(istream & is,Goods & goods);
	friend bool operator<(Goods & goods1, Goods & goods2);
	friend bool operator>(Goods & goods1, Goods & goods2);
	friend bool operator==(Goods & goods1, Goods & goods2);
	//防止因错误输入错误的字符对程序的正常运行造成影响，必须刷新输入流清除储存器中的数据
	Goods();
	Goods(long int goods_ID,string goods_name,int current_stock,int min_stock);
	~Goods();
	
private:
	long int goods_ID;	//商品ID
	string goods_name;	//商品名称
	int current_stock;	//现有库存
	int min_stock;		//最小库存
};

#endif // GOODS_H
