#ifndef __SOURCE_H__
#define __SOURCE_H__

template <typename T>
class Stack
{
public:
	Stack(int s): size(s), top(-1), data(new T[size]){}
    ~Stack() {delete[] data;}
    void push(const T& x) {data[++top] = x;}
    T pop() {return data[top--];}
    int isEmpty() const {return top == -1;}
    int isFull() const {return top == size - 1;}

private:
    int size;
    int top;
    T* data;
};

#endif