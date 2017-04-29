#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nl printf("\n");


// Defining our structure and typedefing it
typedef struct le {
        int zahl;
        struct le * next;
        struct le * prev;
} listenelement;

// typedefing it more , with pointer definition
typedef listenelement * list ;

// creates a new node for a doubly linked list
list getNewNode(int x){
    list newNode = (list)malloc(sizeof(listenelement));
    newNode->zahl = x;
    newNode->next = NULL;
    newNode->prev = NULL;
}

// inserting a list element at the beginning of the list
list insertAtHead (int v,list head){
        list newNode = getNewNode(v);
        if (head == NULL){
            head = newNode;
            return head;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return head;
}

// Deleting the first element / node of the list
list deleteHead (list l){
        if (l == NULL) return l;
        list neu = l->next;
        free(l);
        return neu;
}
// Printing the doubly linked list. the head here is a local pointer
// so we can change it as we want , like : head = head->next;
// without changing the real pointer
void printForward (list head) {
        if (head == NULL) printf("Leer\n");
        else {
            printf("Printing the list forwards : ");
            while(head != NULL){
                printf("%d ",head->zahl);
                head = head->next;
        }
        printf("\n");
    }
}

// printing the doubly linked list in reverse order
void printBackwards (list head) {
        if (head == NULL) printf("Leer\n");
        else {
            while(head->next != NULL){
                head = head->next;
        }
        printf("Printing the list backwards : ");
        while (head != NULL) {
            printf("%d ",head->zahl);
            head = head->prev;
        }
        printf("\n");
    }
}

// counting the elements in the list
int length (list l) {
        int count = 0;
        while(l != NULL){
            count++;
            l = l->next;
        }
        return count;
    }

// deleting all the nodes in a given list ITERATIVE
void deleteAll (list l){
        list neu;
        while (l!=NULL){
                neu = l->next;
                free(l);
                l = neu;
        }
}
// deleting all the nodes in a given list RECURSIVE
void deleteAllrecursive (list l){
        if (l == NULL) return;
        list neu = l->next;
        free(l);
        deleteAllrecursive(neu);
        }

// deleting an element at a given index from the list
list deleteN(int index,list head){
    list temp1 = head;
    if(index==0){
        if(head == NULL){                   // if the list is empty
            printf("The list is empty\n");
            return head;
        }
        head = head->next;
        free(temp1);
        return head;
    }
    for (int i=0;i<index-1;i++){
        temp1 = temp1->next;
        if(temp1->next == NULL){            // checking if the index is between 0 and lenth of the list -1
            printf("Wrong index !\n");      // because in the next step we will set temp2 to temp1->next
            return head;                    // if temp1->next is NULL then we will get an error
        }                                   // trying to access a NULL pointer by doing temp2->next (while temp2 is NULL)
    }
    list temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next->prev = temp1;              // setting the prev of the node
    free(temp2);
    return head;
}

// returns an element at a given index
int get(int index,list head) {
    if(index < 0) {
        printf("Wrong index !\n");
        return -1;
    }
    list temp = head;
    int i = 0;
    while (i < index){
        temp = temp->next;
        i += 1;
        if(temp == NULL){
            printf("Wrong index !\n");
            return -1;
        }
    }
    return temp->zahl;
}

// returns the concatination of 2 given lists
list concat(list seq1,list seq2){
    if(seq1 == NULL){
        return seq2;
    }
    list temp = seq1;
    while (temp->next != NULL) {            // setting temp to the last list element
        temp = temp->next;                  // it will stop when we reach the last list element
    }                                       // because the last element's .next will be NULL
    temp->next = seq2;
    seq2->prev = temp;                      // setting the prev from seq2 to temp
    return seq1;
}




int main(void) {
//                                             *** IMPORTANT ***
    list head = NULL;                       // when we just declare these pointers like
    list head2 = NULL;                      // list head; and list head2; We get a Segmentation fault (core dumped) error

    head = insertAtHead(44,head);
    head = insertAtHead(33,head);
    head = insertAtHead(22,head);
    head = insertAtHead(11,head);

    head2 = insertAtHead(88,head2);
    head2 = insertAtHead(77,head2);
    head2 = insertAtHead(66,head2);
    head2 = insertAtHead(55,head2);


    printForward(head);
    printBackwards(head);
    printf("calling the get() function with index 2 from the head list: %d\n",get(2,head));
    printf("calling the deleteN() function with index 1 ... \n");
    deleteN(1,head);
    printForward(head);
    printBackwards(head);
    printf("calling the concat() function with head and head2 \n");
    head = concat(head,head2);
    printForward(head);
    printBackwards(head);


}
