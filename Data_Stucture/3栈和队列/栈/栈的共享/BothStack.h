#ifndef BOTHSTACK_H
#define BOTHSTACK_H

template <class T, int MaxSize>
class BothStack 
{
private:
    T data[MaxSize];     
    int top1, top2;  
public:
    BothStack();
    ~BothStack(); 
    void Push(int i,T x);   
    T Pop(int i);          
    T GetTop(int i);       
    bool isEmpty(int i);     
};

#endif // BOTHSTACK_H
