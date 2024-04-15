#pragma once
#include <iostream>
using namespace std;

const char* QUEUE_OVERFLOW = "Queue Overflow";
const char* QUEUE_UNDERFLOW = "Queue Underflow";
const char* WRONG_QUEUE_SIZE = "Wrong Queue Size";

template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T& e) = 0;
	virtual T deQueue() = 0;
	virtual bool isEmpty() = 0;
};

class QueueOverflow : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return QUEUE_OVERFLOW;
	}
};

class QueueUnderflow : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return QUEUE_UNDERFLOW;
	}
};

class WrongQueueSize : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return WRONG_QUEUE_SIZE;
	}
};