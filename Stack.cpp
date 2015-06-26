#include "Stack.hpp"


Stack::Stack(){
	size = 1;
	array = new int[size];
}

Stack::Stack(const Stack& other):size(other.size), array(new int[other.size]){
	for (int i = 0; i < size; ++i){
		array[i]=other.array[i];
	}
}

Stack::~Stack(){
	delete[] array;
}

void Stack::push(int newNumber){
	int* stackTemp = new int[++size];
	for(int i = 0; i < size-1 ; i++){
		stackTemp[i] = array[i];
	}
	stackTemp[size-1] = newNumber;
	delete[] array;
	array = stackTemp;
}

int Stack::pop(){
	int resp=0;
	if(size==0){
		throw "Ya no hay elementos";
	}
	resp=array[--size];
	int* temp=new int[size];

	for (int i = 0; i <size; ++i){
		temp[i]=array[i];
	}
	delete[] array;
	array = new int[size];
	for (int i = 0; i < size; ++i){
		array[i]=temp[i];
	}
	return resp;

}

const int Stack::getSize()const{
	return size;
}