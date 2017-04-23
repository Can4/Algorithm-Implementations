
// Stack implementation with arrays in C 
#include <stdio.h>
#define MAX 10
#define StackSize sizeof(Stack)/sizeof(Stack[0])



int Stack[MAX];
int topOfStack = -1;					//keeping track of the Top of stack


void push(int x){							// checking whether the stack is full
	if(topOfStack+1 == StackSize) {			// if its full we return
		printf("The Stack is full !\n");
		return;
	}
	topOfStack = topOfStack + 1;			// if we still have space, we increase our variable by 1
	Stack[topOfStack] = x;					// inserting the new element at that index
	
}

int pop(){
	if(topOfStack==-1){						// checking whether the stack is empty
		printf("The Stack is empty !\n");
		return -1;
	}
	int temp = topOfStack;					// saving the value of topOfStack
	topOfStack -= 1;						// decreasing topOfStack by 1
	printf("Popping the element : %d\n",Stack[temp]);
	return Stack[temp];						// returning the deleted value
}

int top(){
	if(topOfStack==-1){						// checking whether the stack is empty
		printf("The Stack is empty !\n");
		return -1;
	}
	printf("Top element is : %d\n",Stack[topOfStack]);
	return Stack[topOfStack];				// returning the element at the top of the stack
}

int isEmpty(){								// checking whether the stack is empty
	if(topOfStack==-1){						// return 1 if TRUE , 0 if FALSE
		return 1;
	}
	else {
		return 0;
	}
}

void PrintStack(){							// printing stack, if empty it prints : "Empty"
	printf("\nMy Stack : ");
	if(isEmpty()==1) { 
		printf("Empty");
	}
	for(int i=0;i<=topOfStack;i++){
		printf("%d ",Stack[i]);
	}
	printf("\ntopOfStack : %d\n",topOfStack);
}


int main() {

PrintStack();
push(5);
PrintStack();

push(8);
PrintStack();
push(2);
PrintStack();
push(4);
PrintStack();
push(0);
PrintStack();
push(2);
PrintStack();
push(3);
PrintStack();
push(1);
PrintStack();
push(8);
PrintStack();
push(9);
PrintStack();

push(2);
PrintStack();
top();
push(7);
PrintStack();

push(145);
PrintStack();
top();
pop();
PrintStack();

pop();
PrintStack();

pop();
PrintStack();

top();



	return 0;
}
