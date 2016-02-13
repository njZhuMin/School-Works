#ifndef BITREE_H
#define BITREE_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct BiNode		//|lchild|data|rchild|
{					
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};


template <class T>
class BiTree  
{
public:
	BiTree();									//无参构造函数
	BiTree(vector<T> &pre);					//先序构造二叉树
	BiTree(vector<T> &pre, vector<T> &mid);	//先序中序构造二叉树
	BiTree(BiTree<T> &tree);					//拷贝构造二叉树
	~BiTree();									//析构函数
	void PreOrder();							//先序遍历
	void InOrder();								//中序遍历
	void PostOrder();							//后序遍历
	void LevelOrder();							//层次遍历
	int getCount();								//统计结点个数
	int getHeight();								//计算二叉树的高度
	BiNode<T>* Search(T e);						//根据值e查找结点
	BiNode<T>* SearchParent(BiNode<T>* child);	//查找指定结点的父节点


//////私有函数为了在接口函数中调用private的root成员变量//////
private:
	void PreOrder(BiNode<T>* p);				//私有先序遍历函数
	void InOrder(BiNode<T>* p);					//私有中序遍历函数
	void PostOrder(BiNode<T>* p);				//私有后序遍历函数
	BiNode<T>* CreateByPre(vector<T> &pre,int &i);//带空指针标记的先序序列构造二叉树
	BiNode<T>* CreateByMid(vector<T> &pre,vector<T> &mid,int ipre,int imid, int n); //带空指针标记的先序序列构造二叉树
	BiNode<T>* Copy(BiNode<T>* p);				//拷贝构造
	BiNode<T>* Search(BiNode<T>* p,T e);		//二叉树查找
	BiNode<T>* SearchParent(BiNode<T>* p,BiNode<T>* child);		//二叉树查找父亲
	void Free(BiNode<T>* p);					//析构
	int getCount(BiNode<T>* p);					//计算二叉树结点
	int getHeight(BiNode<T>* p);					//计算二叉树高度

private:
	BiNode<T>* root;	//根节点
};

#endif // BITREE_H
