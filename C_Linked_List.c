
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define nl printf("\n");
#define INDEX 4

// Defining our structure and typedefing it
typedef struct le {
        int zahl;
        struct le * next;
} listenelement;

//typedefing it more , with pointer definition
typedef listenelement * list ;

// inserting a list element at the beginning of the list
list insert (int v,list l){
        list neu = (list)malloc(sizeof(listenelement));
        neu->zahl = v;
        neu->next = l;
        return neu;
}
// Deleting the first element / node of the list and returning the 2. element
list deleteHead (list l){
        if (l == NULL) return l;
        list neu = l->next;
        free(l);
        return neu;
}
// Printing the list. the l here is a local pointer
// so we can change it as we want , like : l = l->next;
// without changing the real pointer
void printList (list l) {
        if (l == NULL) printf("Leer\n");
        else {
            while(l != NULL){
                printf("%d ",l->zahl);
                l = l->next;
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

// reversing the order in a list
list reverse(list head) {
        list current, prev, nextPointer;
        current = head;
        prev = NULL;
        while(current != NULL){
            nextPointer = current->next;
            current->next = prev;
            prev = current;
            current = nextPointer;
        }
        head = prev;
        return head;
}

// Deleting a given element "e" from a list
// Returning the list without the element "e" in it.

list deleteElem(int e,list head){
    if (head == NULL) return head;
    list temp,prev,forward;     // Create pointers
    temp = head;                // setting temp equal to head

    while(temp != NULL) {
        forward = temp->next;       // forward will be the next node from temp
        if (temp->zahl == e) {      // if the number is the one we want to delete

            if (temp == head){      // and if temp is still at the head node , meaning we deleted all nodes we checked till now
                                    // or we are just starting to delete
                head = head->next;  // adjusting the head pointer to the next node because we will delete the head node
                free(temp);         // delete the node that temp points to
                prev = forward;     // set the prev pointer to the next node
            }
            // if we didnt delete a node already
            else {
                prev->next = forward;   // adjust the links so it wont point to the node that will be deleted, but it will point to the next one
                free(temp);             // delete the node
            }
        }
        else {              // if the number of the node is not equal to "e"
            prev = temp;    // just adjusting previous
        }
        temp = forward;     // check the next node
    }
    return head;
}

// This function looks if the list is ordered ascanding or descending
int sorted(int zahl,list head){
    int temp;                               // our temporary number holder
    temp = head->zahl;
    if(zahl == 1){
        while(head->next != NULL){          // check if we reached the end of the list
            if (temp >= head->next->zahl){  // check if the next number in the list is smaller or equal
                temp= head->next->zahl;     // if so then update our temp to that next number
                head= head->next;           // change the head to the next node
            }
            else {return -1;}               // if our number is not smaller or equal then return -1
        }                                   // to say that the list isnt ordered
        return 1;
    }
    else if (zahl == 0) {                   // exact same here
        while(head->next != NULL){
            if (temp <= head->next->zahl){
                temp= head->next->zahl;
                head= head->next;
            }
            else {return -1;}
        }
        return 1;
    }
    else printf("\nGeben sie 0 oder 1 ein\n");
}
// deleting an element at a given index from the list
list deleteN(int index,list head){
    list temp1 = head;
    if(index==0){
        if(head == NULL){                   // if the list is empty
            printf("The list is empty\n");
            return head;
        }
        head = temp1->next;
        free(temp1);
        return head;
    }
    for (int i=0;i<index-1;i++){
        temp1 = temp1->next;
        if(temp1->next == NULL){            // checking if the index is between 0 and lenth of the list -1
            printf("Wrong index !\n");      // because in the next step we will set temp2 to temp1->next
            return head;                    // if temp1->next is NULL then we will get an error, trying to access a NULL pointer
        }                                   // by doing temp2->next (while temp2 is NULL)
    }
    list temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;


}

int main(void) {

    list head = NULL;


    head = insert (44,head);
    head = insert (33,head);
    head = insert (22,head);
    head = insert (11,head);
    printList(head);
    printf("Deleting at index %d\n",INDEX);
    head = deleteN(INDEX,head);
    printList(head);












   /* int zahl = 5;
    printf("The list before deletion of the number : %d\n",zahl);
    printList(head); nl

    head = deleteElem(zahl,head);
    printf("The list after deletion of the number : %d\n",zahl);
    printList(head); nl nl

    head = reverse(head);
    printList(head); nl

    head = NULL;
    printList(head);    */






   /* int a = 10;                 // burayı silince çalışıyor
    int * abc = &a;
    printf("\n %d",*abc);
*/

}

/* // if (l == NULL) return NULL;
        list n1 = l->next;
        list n2 = l->next;
        l->next = NULL;
        while(n2!=NULL) {
                n2 = n1->next;
                n1->next = l;
                l = n1;
                n1 = n2;
        }
        return l;
        */
