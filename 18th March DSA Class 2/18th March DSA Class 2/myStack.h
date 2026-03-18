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
    myStack<T>* minStack;
public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
        minStack = new myStack<T>(size, true);
    }
    myStack(int size, bool helper) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
        minStack = nullptr;
    }
    ~myStack() {
        delete[] arr;
        if (minStack) delete minStack;
    }
    void push(T value) {
        if (!isFull()) {
            arr[++topIndex] = value;
            if (minStack->isEmpty() || value <= minStack->top())
                minStack->push(value);
        }
        else cout << "Stack Overflow" << endl;
    }
    T pop() {
        if (!isEmpty()) {
            T val = arr[topIndex--];
            if (val == minStack->top())
                minStack->pop();
            return val;
        }
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
    bool isEmpty() const { return topIndex == -1; }
    bool isFull() const { return topIndex == capacity - 1; }
    void display() const {
        if (isEmpty()) cout << "Stack is Empty" << endl;
        else {
            for (int i = topIndex; i >= 0; i--) cout << arr[i] << " ";
            cout << endl;
        }
    }
    T getMin() const {
        if (!minStack->isEmpty()) return minStack->top();
        else {
            cout << "No minimum, stack empty" << endl;
            return T();
        }
    }
};

#endif
