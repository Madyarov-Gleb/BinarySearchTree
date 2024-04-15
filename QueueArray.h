#pragma once
#include "Queue.h"

template <class T>
class QueueArray : public Queue<T>
{
private:
	T* data;
	int head = 0;
	int tail = 0;
	int maxSize;
	int sizeQueue;
public:
	QueueArray(int size);
	~QueueArray();
	void enQueue(const T& e) override;
	T deQueue() override;
	bool isEmpty();
	void outPut();
	int getSize();
	T Head();
};

template <class T>
QueueArray<T>::QueueArray(int size) {
	if (size < 0) {
		throw WrongQueueSize();
	}
	maxSize = size;
	data = new T[size];
	tail = -1;
	sizeQueue = 0;
}

template <class T>
QueueArray<T>::~QueueArray() {
	delete[] data;
}

template <class T>
void QueueArray<T>::enQueue(const T& e) {
	if (tail == maxSize - 1 && head != NULL) {
		throw QueueOverflow();
	}
	data[++tail] = e;
	sizeQueue++;
}

template <class T>
T QueueArray<T>::deQueue() {
	if (tail == -1) {
		throw QueueUnderflow();
	}
	data[head] = NULL;
	sizeQueue--;
	return data[++head];
}

template <class T>
bool QueueArray<T>::isEmpty() {
	return (sizeQueue == 0);
}

template <class T>
void QueueArray<T>::outPut() {
	int container = head;
	while (head <= tail) {
		cout << data[head] << " ";
		head++;
	}
	head = container;
	cout << endl;
}

template <class T>
int QueueArray<T>::getSize() {
	return sizeQueue;
}

template <class T>
T QueueArray<T>::Head() {
	return data[head];
}

