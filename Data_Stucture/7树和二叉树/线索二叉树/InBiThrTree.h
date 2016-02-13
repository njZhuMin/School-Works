#ifndef INBITHRTREE_H
#define INBITHRTREE_H
#include <iostream>
#include <vector>
using namespace std;

enum BiThrNodeType{LINK,THREAD};

template <class T>
struct BiThrNode
{
	BiThrNodeType ltype, rtype;
	T data;
	BiThrNode<T>*lchild, *rchild;
};

template <class T>
class InBiThrTree
{
private:
	BiThrNode<T>* root;
	
public:
	InBiThrTree();
	InBiThrTree(vector<T> &pre);	//先序序列创建二叉树
	void InThreaded();				//中序线索化接口函数
	~InBiThrTree();					//析构函数
	BiThrNode<T>* getNext(BiThrNode<T>* p);		//中序遍历中的后继结点
	BiThrNode<T>* getPrev(BiThrNode<T>* p);		//中序遍历中的前驱结点
	void Travese();								//利用线索中序遍历
	BiThrNode<T>* getParent(BiThrNode<T>* p);	//求父结点
	
private:
	void InThreaded(BiThrNode<T>* &p);	//中序线索化私有函数
	void Free(BiThrNode<T>* p);			//析构
	BiThrNode<T>* CreateByPre(vector<T> &pre, int &i);	//先序创建
};

#endif // INBITHRTREE_H
