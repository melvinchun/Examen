#include "Stack.hpp"


Stack::Stack(){
	size = 1;
	array = new int[size];
}
Stack::Stack(const Stack&){

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

}
const int Stack::getSize()const{

}