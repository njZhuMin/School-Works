#include "BiSortTree.h"
#include <iostream>
using namespace std;

BiSortTree::BiSortTree()
{
}

/**
 * @brief 二叉树的建立
 * @param a
 * @param n
 * @return 
 */
BiSortTree::BiSortTree(int a[], int n)
{
	root = NULL;
	for(int i = 0; i < n; i++)  
		Insert(root, a[i]);
}

BiSortTree::~BiSortTree()
{
	Free(root);
}

/**
 * @brief 私有插入函数	
 * @param ptr
 * @param k
 */  
//////////可能要改变根结点的地址，所以传的是二级指针//////////
void BiSortTree::Insert(BiNode* &ptr, int k)
{
	//初始化插入结点  
	BiNode* p = new BiNode;  
	p->key = k;  
	p->lchild = p->rchild = p->parent = NULL;  
	
	//空树时，直接作为根结点  
	if(ptr == NULL)
	{  
		ptr = p;  
		return;  
	} 
	
	//插入到当前结点ptr的左孩子  
	if(ptr->lchild == NULL && ptr->key > k)
	{  
		p->parent = ptr;  
		ptr->lchild = p;  
		return;  
	}
	
	//插入到当前结点ptr的右孩子  
    if(ptr->rchild == NULL && ptr->key < k)
	{  
		p->parent = ptr;  
		ptr->rchild= p;  
		return;  
	}
	
	//递归插入树表
	if(k < ptr->key)  
		Insert(ptr->lchild, k);  
    else if(k > ptr->key)  
		Insert(ptr->rchild, k); 
    else  
        return;  
}

/**
 * @brief 公有插入函数
 * @param k
 */
void BiSortTree::Insert(int k)
{
	Insert(root, k);
}

/**
 * @brief 私有非递归查找函数
 * @param ptr
 * @param k
 */
BiNode* BiSortTree::non_recursiveSearch(BiNode* ptr, int k)
{
	if(ptr == NULL)  
		return NULL;  
	//查找左子树
	if(k < ptr->key) 			  
		return non_recursiveSearch(ptr->lchild, k);  
    //查找右子树
	else if(k > ptr->key) 	 
		return non_recursiveSearch(ptr->rchild, k);  
    else  
		return ptr; 
}

/**
 * @brief 公有非递归查找函数
 * @param k
 * @return 
 */
bool BiSortTree::non_recursiveSearch(int k)
{
	return (non_recursiveSearch(root, k) != NULL);
}

/**
 * @brief 私有递归查找函数
 * @param ptr
 * @param k
 */
BiNode* BiSortTree::recursiveSearch(BiNode* ptr, int k)
{
	while(ptr)
	{
		//查找左子树
		if(k < ptr->key) 			  
			return recursiveSearch(ptr->lchild, k);  
		//查找右子树
		else if(k > ptr->key) 	 
			return recursiveSearch(ptr->rchild, k);  
		else  
			return ptr; 
	}
	return NULL;
	
}

/**
 * @brief 公有递归查找函数
 * @param k
 * @return 
 */
bool BiSortTree::recursiveSearch(int k)
{
	return (recursiveSearch(root, k) != NULL);
}

/**
 * @brief 查找最小关键字,空树时返回NULL
 * @param ptr
 * @return 
 */  
BiNode* BiSortTree::searchMin(BiNode* &ptr)  
{  
	if(ptr == NULL)  
		return NULL;  
	if(ptr->lchild == NULL)  
		return ptr;  
	else  //一直往左孩子找，直到没有左孩子的结点  
		return searchMin(ptr->lchild);  
}  
  
/**
 * @brief 查找最大关键字,空树时返回NULL 
 * @param ptr
 * @return 
 */ 
BiNode* BiSortTree::searchMax(BiNode* &ptr)
{  
    if(ptr == NULL)  
		return NULL;  
    if(ptr->rchild == NULL)  
		return ptr;  
	else  //一直往右孩子找，直到没有右孩子的结点  
		return searchMax(ptr->rchild);  
}  
  
/**
 * @brief 查找某个结点的前驱
 * @param p
 * @return 
 */  
BiNode* BiSortTree::searchPredecessor(BiNode* &ptr)
{   
	if(ptr == NULL)  
		return ptr;  
	//有左子树、左子树中最大的那个  
	if(ptr->lchild)  
		return searchPredecessor(ptr->lchild);  
	//无左子树,查找某个结点的右子树遍历完了  
	else
	{  
		if(ptr->parent == NULL)  
			return NULL;  
		//向上寻找前驱  
		while(ptr)
		{  
			if(ptr->parent->rchild == ptr)  
				break;  
			ptr = ptr->parent;  
		}  
		return ptr->parent;  
	}  
}  
  
/**
 * @brief 查找某个结点的后继 
 * @param p
 * @return 
 */ 
BiNode* BiSortTree::searchSuccessor(BiNode* &ptr)
{  
	if(ptr == NULL)  
		return ptr;  
	//有右子树、右子树中最小的那个  
	if(ptr->rchild)  
		return searchMin(ptr->rchild);  
	//无右子树,查找某个结点的左子树遍历完了  
    else
	{  
		if(ptr->parent == NULL)  
			return NULL;  
		//向上寻找后继  
		while(ptr)
		{  
			if(ptr->parent->lchild == ptr)  
				break;  
			ptr = ptr->parent;  
		}  
		return ptr->parent;  
	}  
}

//查找最小关键字
BiNode* BiSortTree::searchMin()
{
	return searchMin(root);			
}

//查找最大关键字
BiNode* BiSortTree::searchMax()
{
	return searchMax(root);			
}

/////如果把根结点删掉，那么要改变根结点的地址，所以传二级指针/////
/**
 * @brief 私有删除函数
 * @param ptr
 * @param key
 * @return 
 */
bool BiSortTree::Delete(BiNode* &ptr, int k)  
{  
    BiNode* q;
	int temp;
    //查找到要删除的结点  
    BiNode* p = recursiveSearch(ptr, k);  
    //没查到此关键字  
    if(p == NULL)  
		return false;  
    
	//1.被删结点是叶子结点，直接删除  
    if(p->lchild == NULL && p->rchild == NULL)
	{  
		//只有一个元素，删完之后变成一颗空树  
		if(p->parent == NULL)
		{  
			Free(p);  
			ptr = NULL;  
		}
		else	//删除的结点是父节点的左孩子
		{  
			if(p->parent->lchild == p)  
				p->parent->lchild = NULL;  
			else  //删除的结点是父节点的右孩子  
				p->parent->rchild = NULL;  
			Free(p);  
        }  
	}  
  
    //2.被删结点只有左子树  
	else if(p->lchild && !(p->rchild))
	{  
		p->lchild->parent = p->parent;  
		//如果删除是父结点，要改变父节点指针  
		if(p->parent == NULL)  
			ptr= p->lchild;  
		//删除的结点是父节点的左孩子  
		else if(p->parent->lchild == p)  
			p->parent->lchild = p->lchild;  
		//删除的结点是父节点的右孩子
		else   
			p->parent->rchild = p->lchild;  
       Free(p);  
	} 
 
    //3.被删结点只有右孩子  
	else if(p->rchild && !(p->lchild))
	{  
		p->rchild->parent = p->parent;  
		//如果删除是父结点，要改变父节点指针  
		if(p->parent == NULL)  
			ptr = p->rchild;  
		//删除的结点是父节点的左孩子  
		else if(p->parent->lchild == p)  
			p->parent->lchild=p->rchild;  
		//删除的结点是父节点的右孩子
		else 
			p->parent->rchild = p->rchild;  
       Free(p);  
    } 
	
    //4.被删除的结点既有左孩子，又有右孩子  
    //该结点的后继结点肯定无左子树(参考上面查找后继结点函数)  
    //删掉后继结点,后继结点的值代替该结点  
	else
	{  
		//找到要删除结点的后继  
		q = searchSuccessor(p);  
		temp = q->key;  
		//删除后继结点  
		Delete(root, q->key);  
		p->key = temp;  
	}  
	return true;  
} 

/**
 * @brief 公有删除函数
 * @param k
 * @return 
 */
bool BiSortTree::Delete(int k)
{
	return Delete(root, k);
}

void BiSortTree::Free(BiNode* ptr)
{
	if(ptr == NULL)
		return;
	Free(ptr->lchild);	//释放左子树
	Free(ptr->rchild);	//释放右子树
	Free(ptr->parent);	//释放父结点
	delete ptr;		//释放根结点

}