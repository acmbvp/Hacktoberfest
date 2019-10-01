#include <stdio.h>
#include <stdbool.h>

int STACK_SIZE = 10;
int stack[10];
int size = 0; // Acts as top pointer. 
	
bool isEmpty(){
	return(size == 0);
}

int top(){
	int emt = isEmpty();
	if(emt == 1){
		printf("This stack is empty...\n");
		return -1;
	} else {

	return stack[size -1];
	}
}

void push(int input){
	if(size == STACK_SIZE){
		printf("This stack is full...\n");
	} else {
		stack[size] = input;
		size++;
	}
}

int pop(){
	int emt = isEmpty();
	if(emt == 1){
		printf("This stack is empty...\n");
		return -1;
	} else {
		int top = stack[size-1];
		size--;

		return top;

	}
}

int main(){
	// Could be used with a command parser  but the base of the Stack is built.
	// Add test code and try to break it!
}