#ifndef BISORTTREE_H
#define BISORTTREE_H

struct BiNode	//结点结构定义
{
	int key;
	BiNode* lchild;
	BiNode* rchild;
	BiNode* parent;
};

class BiSortTree
{
public:
	BiSortTree();
	BiSortTree(int a[], int n);	//含参构造函数
	void Insert(int k);		//公有插入函数
	bool non_recursiveSearch(int k);	//公有非递归查找函数
	bool recursiveSearch(int k);			//公有递归查找函数
	BiNode* searchMin();				//查找最小关键字
	BiNode* searchMax();				//查找最大关键字
	BiNode* searchPredecessor(BiNode* &ptr);		//查找某个结点的前驱
	BiNode* searchSuccessor(BiNode* &ptr);			//查找最大关键字
	bool Delete(int k);		//公有删除函数
	~BiSortTree();
	
private:
	BiNode* root;
	void Insert(BiNode* &ptr, int k);		//私有插入函数
	BiNode* non_recursiveSearch(BiNode* ptr, int k);		//私有非递归查找函数
	BiNode* recursiveSearch(BiNode* ptr, int k);		//私有递归查找函数
	BiNode* searchMin(BiNode* &ptr);				//查找最小关键字
	BiNode* searchMax(BiNode* &ptr);				//查找最大关键字
	bool Delete(BiNode* &ptr, int k);		//私有删除函数
	void Free(BiNode* ptr);
};

#endif // BISORTTREE_H
