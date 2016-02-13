#include "BiTree.h"
#include "LinkQueue.h"
#include <iostream>

/**
 * @brief 二叉树空构造函数
 */
template <class T>
BiTree<T>::BiTree()
{
	root = NULL;
}

/**
 * @brief 带空指针标记（*）的先序私有构造函数
 * @param pre
 * @param i
 * @return 
 */
template <class T>
BiNode<T>* BiTree<T>::CreateByPre(vector<T> &pre,int &i)
{
	T e = pre[i];	//获得当前数据
	i++;
	if(e == '*')		//若为空数据标记，返回空指针
		return NULL;
	BiNode<T>* p = new BiNode<T>;		//创建新结点
	p->data = e;
	p->lchild = CreateByPre(pre,i);		//创建左子树
	p->rchild = CreateByPre(pre,i);		//创建右子树
	return p;
}

/**
 * @brief 先序构造函数
 * @param pre
 */
template <class T>
BiTree<T>::BiTree(vector<T> &pre)
{
	int i = 0;
	root = CreateByPre(pre,i);
}

/**
 * @brief 先序、中序构造函数
 * @param pre 前序序列指针
 * @param mid 中序序列指针
 */
template <class T>
BiTree<T>::BiTree(vector<T> &pre,vector<T> &mid)	//先序、中序构造二叉树
{
	int n = pre.size();
	root = CreateByMid(pre,mid,0,0,n);
}

/**
 * @brief 带空指针标记（*）的先序私有构造函数
 * @param pre 前序序列指针
 * @param mid 中序序列指针
 * @param ipre	前序序列
 * @param imid	中序序列
 * @param n	总数
 * @return 
 */
template <class T>
BiNode<T>* BiTree<T>::CreateByMid(vector<T> &pre,vector<T> &mid,int ipre,int imid, int n)
{
	int i;
	if(n == 0)
		return NULL;
	BiNode<T>* p=new BiNode<T>;
	p->data = pre[ipre];
	for(i = 0; i < n; i++)
		if(pre[ipre]==mid[imid+i])
			break;	
	p->lchild = CreateByMid(pre,mid,ipre+1,imid,i);
	p->rchild = CreateByMid(pre,mid,ipre+i+1,imid+i+1,n-i-1);
	return p; 
}

/**
 * @brief 拷贝构造函数
 * @param tree
 */
template <class T>
BiTree<T>::BiTree(BiTree <T> &tree)
{
	root = Copy(tree.root);
}

/**
 * @brief 拷贝构造生成树
 * @param p
 * @return 
 */
template <class T>
BiNode<T>* BiTree<T>::Copy(BiNode<T>* p)
{
	if(p == NULL)
		return NULL;
	BiNode<T>* newp = new BiNode<T>;
	newp->data   = p->data;
	newp->lchild = Copy(p->lchild);
	newp->rchild = Copy(p->rchild);
	return newp;
}

/**
 * @brief 先序遍历私有函数
 * @param p
 */
template <class T>
void BiTree<T>::PreOrder(BiNode<T>* p)
{
	if(p == NULL)	//二叉树为空，遍历结束
		return;
	cout << p->data;	//访问结点
	PreOrder(p->lchild);	//先序遍历当前结点lchild
	PreOrder(p->rchild);	//先序遍历当前结点rchild
}

/**
 * @brief 先序遍历接口函数
 */
template <class T>
void BiTree<T>::PreOrder()		
{
	PreOrder(root);
}

/**
 * @brief 中序遍历私有函数
 * @param p
 */
template <class T>
void BiTree<T>::InOrder(BiNode<T>* p)
{
	if(p == NULL)
		return;
	InOrder(p->lchild);
	cout<<p->data;
	InOrder(p->rchild);
}

/**
 * @brief 中序遍历接口函数
 */
template <class T>
void BiTree<T>::InOrder()
{
	InOrder(root);
}

/**
 * @brief 后序遍历私有函数
 * @param p
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T>* p)
{
	if(p == NULL)
		return;
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout<<p->data;
}

/**
 * @brief 后序遍历接口函数
 */
template <class T>
void BiTree<T>::PostOrder()
{
	PostOrder(root);
}

/**
 * @brief 层次遍历函数
 */
template <class T>
void BiTree<T>::LevelOrder()
{
	if(root == NULL)		//二叉树为空，遍历结束
		return;
	LinkQueue<BiNode<T>* > Q;
	Q.EnQueue(root);		//根结点指针入队列
	while(!Q.isEmpty())		//指针队列不为空，循环递归查找下一层
	{
		BiNode<T>* p = Q.DeQueue();		//出队列，得到指针p
		cout << p->data;					//访问p结点
		//若有lchild,rchild则指针进队列
		if(p->lchild != NULL)
			Q.EnQueue(p->lchild);
		if(p->rchild != NULL)
			Q.EnQueue(p->rchild);
	}
}

/**
 * @brief 二叉树析构函数
 */
template <class T>
BiTree<T>::~BiTree()
{
	Free(root);
}

/**
 * @brief 二叉树结点释放函数
 * @param p
 */
template <class T>
void BiTree<T>::Free(BiNode<T>* p)
{
	if(p == NULL)
		return;
	Free(p->lchild);	//释放左子树
	Free(p->rchild);	//释放右子树
	delete p;			//释放根结点
}

/**
 * @brief 计算二叉树结点个数接口函数
 * @return 
 */
template <class T>
int BiTree<T>::getCount()
{
	return getCount(root);
}

/**
 * @brief 计算二叉树结点个数私有函数
 * @param p
 * @return int
 */
template <class T>
int BiTree<T>::getCount(BiNode<T>* p)
{
	if(p == NULL)
		return 0;
	int left  = getCount(p->lchild);	//计算所有左子树结点个数
	int right = getCount(p->rchild);	//计算所有右子树结点个数
	return (1 + left + right);
}

/**
 * @brief 计算二叉树高度接口函数
 * @return int 
 */
template <class T>
int BiTree<T>::getHeight()
{
	return getHeight(root);
}

/**
 * @brief 计算二叉树高度接口函数
 * @return int 
 */
template <class T>
int BiTree<T>::getHeight(BiNode<T>* p)
{
	if(p == NULL)
		return 0;
	int left = getHeight(p->lchild);
	int right = getHeight(p->rchild);
	return (left > right ? (left + 1) : (right + 1));
}

/**
 * @brief 按值查找接口函数
 * @param e
 * @return *p
 */
template <class T>
BiNode<T>* BiTree<T>::Search(T e)
{
	return Search(root,e);
}

/**
 * @brief 按值查找私有函数
 * @param p
 * @param e
 * @return *p
 */
//TODO 二叉树按值查找，不能完成对所有结点的遍历
//TODO 若要完成对整个树的遍历查找，在遍历函数中新增队列储存节点再访问
template <class T>
BiNode<T>* BiTree<T>::Search(BiNode<T>* p,T e)
{
	if(p == NULL)
		return NULL;
	if(p->data == e)
		return p;
	BiNode<T>* q = Search(p->lchild, e);
	if(q != NULL)
		return q;
	return Search(p->rchild,e);
}

/**
 * @brief 查找任意结点父结点接口函数
 * @param child
 * @return 
 */
template <class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* child)
{
	return SearchParent(root,child);
}

/**
 * @brief 查找任意结点点父结点私有函数
 * @param p
 * @param child
 * @return 
 */
template <class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* p,BiNode<T>* child)
{
	if(p == NULL || child == NULL)	//查找失败
		return NULL;
	if(p->lchild == child || p->rchild == child)
		return p;
	BiNode<T>* q = SearchParent(p->lchild,child);
	if(q != NULL)
		return q;
	return SearchParent(p->rchild,child);
}