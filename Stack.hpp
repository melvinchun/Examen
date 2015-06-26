#pragma once


class Stack{
	int size;
	int* array;
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	void push(int);
	int pop();
	const int getSize()const;
};