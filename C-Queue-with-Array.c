
// Queue implementation with arrays in C
#include <stdio.h>
#define MAX 10



int Queue[MAX];						// This is our Queue[10]
int rear = -1;						// rear contains the variable of the last index of Queue
int front = -1;						// front contains the variable of the first index of Queue

int IsEmpty(){
	if(rear==-1 && front== -1){		// if both are -1 , it means the Queue is empty
		return 1;
	}
	else{
		return 0;
	}
}

void EnQueue(int x) {
	if ((rear+1)%MAX ==front) {				// if rear+1 == front , it means the Queue has no room for a new element
		printf("The Queue is full !");
		return;
	}
	else if (IsEmpty()) {					// if Queue is empty , first we set both variables to 0
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear+1) % MAX;				// if the Queue has some elements and also free space for a new element
	}
	Queue[rear] = x;						// and here we add the new element to the corresponding index
}


int DeQueue(){								// if Queue is empty there is no element to return
	if (IsEmpty()) {
		printf("The Queue is empty !");
		return -1;
	}
	else if (rear == front){				// if rear == front , it means the Queue has only one element
		int temp = rear;					// first we save the number in rear, because we will change rear before returning something
		rear = -1;							// then we set the Queue to empty again  *rear = -1 front = -1*
		front = -1;
		printf(" ** DeQueued number is : %d **\n",Queue[temp]);
		return Queue[temp];					// and we print and return the value that we deleted from the Queue
	}
	else { 
		int temp = front;					// otherwise saving the front value 
		front = (front+1) % MAX;			// increasing front by 1 because we are deleting the first element
		printf(" ** DeQueued number is : %d **\n",Queue[temp]);	
		return Queue[temp];					// and returning the element that we deleted from the Queue
	}
}
int Front(){
	if (IsEmpty()==0) {						// if the Queue is NOT empty, print the top element and also return the top element
		printf("Top of the Queue is : %d\n",Queue[front]);
		return Queue[front];
	}
	printf("The Queue is empty !\n\n");
	return -10000;							
}

void PrintQueue() {							// Printing the Queue, starting from front till rear
	printf("\nMy Queue : ");				
	for(int i=front;i<=rear;i++){
		if (IsEmpty()){
			printf("Empty");
			printf("\n\t Rear : %d    Front : %d \n",rear,front);
			return;
		}									
		printf("%d ",Queue[i]);
	}
	printf("\n\t Rear : %d    Front : %d \n",rear,front);
}


int main() {

	PrintQueue();
	
	EnQueue(7); 
	PrintQueue();
	
	EnQueue(4); 
	PrintQueue();

	EnQueue(2); 
	PrintQueue();

	Front();
	printf("\t Rear : %d    Front : %d \n",rear,front);

	DeQueue(); 
	PrintQueue();
	Front();

	DeQueue(); 
	PrintQueue();
	Front();

	DeQueue(); 
	PrintQueue();

	DeQueue(); 
	PrintQueue();
	Front();


	return 0;
}

