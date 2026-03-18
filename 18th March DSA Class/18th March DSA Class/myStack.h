#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int capacity;
    int topIndex;
public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }
    ~myStack() {
        delete[] arr;
    }
    void push(T value) {
        if (!isFull()) arr[++topIndex] = value;
        else cout << "Stack Overflow" << endl;
    }
    T pop() {
        if (!isEmpty()) return arr[topIndex--];
        else {
            cout << "Stack Underflow" << endl;
            return T();
        }
    }
    T top() const {
        if (!isEmpty()) return arr[topIndex];
        else {
            cout << "Stack is Empty" << endl;
            return T();
        }
    }
    bool isEmpty() const {
        return topIndex == -1;
    }
    bool isFull() const {
        return topIndex == capacity - 1;
    }
    void display() const {
        if (isEmpty()) cout << "Stack is Empty" << endl;
        else {
            for (int i = topIndex; i >= 0; i--) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

#endif
