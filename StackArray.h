#pragma once
#include "Stack.h"

template <class T>
class StackArray : public Stack<T> {
private:
	T* data;
	int maxSize;
	int top;
public:
	StackArray(int size);
	~StackArray();
	void push(const T& e) override;
	T pop() override;
	bool isEmpty() override;
	void outPut();
	T Top();
	int getTop();
};

template <class T>
StackArray<T>::StackArray(int size) {
	if (size <= 0) {
		throw WrongStackSize();
	}
	maxSize = size;
	data = new T[size];
	top = -1;
}

template <class T>
StackArray<T>::~StackArray() {
	delete[] data;
}

template <class T>
void StackArray<T>::push(const T& e) {
	if (top == maxSize - 1) {
		throw StackOverflow();
	}
	data[++top] = e;
}

template <class T>
T StackArray<T>::pop() {
	if (top == -1) {
		throw StackUnderflow();
	}
	data[top] = 0;
	top--;
	return data[top];
}

template <class T>
bool StackArray<T>::isEmpty() {
	return (top == -1);
}

template <class T>
void StackArray<T>::outPut() {
	int i = 0;
	while (i <= top) {
		cout << data[i] << " ";
		i++;
	}
	cout << endl;
}

template <class T>
T StackArray<T>::Top() {
	return data[top];
}

template <class T>
int StackArray<T>::getTop() {
	return top;
}
