#include "InBiThrTree.h"
/**
 * @brief 空构造函数
 */
template <class T>
InBiThrTree<T>::InBiThrTree()
{
	root = NULL;
}

/**
 * @brief 先序构造函数
 * @param pre
 */
template <class T>
InBiThrTree<T>::InBiThrTree(vector<T> &pre)
{
	int i = 0;
	root = CreateByPre(pre,i);
}

/**
 * @brief 私有构造函数
 * @param pre
 * @param i
 * @return p
 */
template <class T>
BiThrNode<T>* InBiThrTree<T>::CreateByPre(vector<T> &pre, int &i)
{
	T e = pre[i];
	i++;
	if(e == '*')
		return NULL;
	BiThrNode<T>* p = new BiThrNode<T>;
	p->data = e;
	
	p->lchild = CreateByPre(pre,i);
	if(p->lchild == NULL)
	{
		p->ltype = THREAD;
	}
	else
	{
		p->ltype = LINK;
	}

	p->rchild = CreateByPre(pre,i);
	if(p->rchild == NULL)
	{
		p->rtype = THREAD;
	}
	else
	{
		p->rtype = LINK;
	}
	
	return p;
}

/**
 * @brief 中序线索化接口函数
 */
template <class T>
void InBiThrTree<T>::InThreaded()
{
	InThreaded(root);
}

/**
 * @brief 中序线索化私有函数
 * @param p
 */
template <class T>
void InBiThrTree<T>::InThreaded(BiThrNode<T>* &p)
{
	if(p == NULL)	//若二叉链表p为空，空操作返回
		return;
	InThreaded(p->lchild);	//建立左子树线索
	BiThrNode<T>* preNode = NULL;
	//对p结点建立线索
	if(p->lchild == NULL)		//对p左指针处理
	{
		p->ltype = THREAD;
		p->lchild = preNode;
	}
	if(p->rchild == NULL)		//对p右指针处理
	{
		p->rtype = THREAD;
	}
	
	if(preNode != NULL)
	{
		if(preNode->rtype == THREAD)	//设置preNode后继线索
			preNode->rchild = p;
	}
	preNode = p;
	
	//对p右子树建立线索
	InThreaded(p->rchild);
}

/**
 * @brief 求结点后继指针算法
 * @param p
 * @return p
 */
template <class T>
BiThrNode<T>* InBiThrTree<T>::getNext(BiThrNode<T> *p)
{
	if(p->rtype == THREAD)
		return (p->rchild);
	p = p->rchild;
	while(p->ltype == LINK)
	{
		p = p->lchild;
	}
	return p;
}

/**
 * @brief 求结点前驱指针算法
 * @param p
 * @return p
 */
template <class T>
BiThrNode<T>* InBiThrTree<T>::getPrev(BiThrNode<T>* p)
{
	if(p->ltype == THREAD)
		return p->lchild;
	p = p->lchild;
	while(p->rtype == LINK)
	{
		p = p->rchild;
	}
	return p;
}

/**
 * @brief 中序遍历线索二叉树
 */
template <class T>
void InBiThrTree<T>::Travese()
{
	BiThrNode<T>* p = root;
	while(p->ltype == LINK)	//找到中序遍历起点
	{
		p = p->lchild;
	}
	while(p != NULL)
	{
		cout << p->data << " ";
		p = getNext(p);
	}
}

/**
 * @brief 
 * @param p
 * @return parent 
 */
template <class T>
BiThrNode<T>* InBiThrTree<T>::getParent(BiThrNode<T>* p)
{
	if(p == NULL)
		return NULL;
	BiThrNode<T>* parent = NULL;
	parent = p;
	while(parent->rtype == LINK)
	{
		parent = parent->rchild;
	}
	parent = parent->rchild;	//parent是*p最右下方结点的后继指针
	if(parent && parent->lchild == p)	//判断*p是否为*parent的lchild
		return parent;
	
	parent = p;
	while(parent->ltype == LINK)
	{
		parent = parent->lchild;
	}
	parent = parent->lchild;
	return parent;
}

/**
 * @brief 线索二叉树析构函数
 */
template <class T>
InBiThrTree<T>::~InBiThrTree()
{
	Free(root);
}

template <class T>
void InBiThrTree<T>::Free(BiThrNode<T>* p)
{
	if(p == NULL)
		return;
	Free(p->lchild);	//释放左子树
	Free(p->rchild);	//释放右子树
	delete p;			//释放根结点
}

