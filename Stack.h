#pragma once
#include <iostream>
using namespace std;

const char* STACK_OVERFLOW = "Stack Overflow";
const char* STACK_UNDERFLOW = "Stack Underflow";
const char* WRONG_STACK_SIZE = "Wrong Stack Size";

template <class T>
class Stack {
public:
	virtual ~Stack() {};
	virtual void push(const T& e) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};

class StackOverflow : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return STACK_OVERFLOW;
	}
};

class StackUnderflow : public std::exception {
public:
	const char* what() const noexcept override {
		return STACK_UNDERFLOW;
	}
};

class WrongStackSize : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return WRONG_STACK_SIZE;
	}
};