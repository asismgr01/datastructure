#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack* next;
};
struct stack* top;
int push(int data);
void pop();
void traverse(struct stack* top);
int is_empty();
int peek();
int main()
{
    // push the elements of stack
    push(5);/*test cases*/
    push(9);
    push(7);
    push(1);
    traverse(top);// display stack elements
    pop();// delete top elements of stack
    traverse(top);// display stack elements
    printf("\nTop element of stack is %d.",peek());// print top elementof stack
    return 0;
}
// function to add an element data in the stack
// insert at the beginning
int push(int data){
    // create new node temp and allocate memory
    struct stack* temp;
    temp = (struct stack*)malloc(sizeof(struct stack));

    // check if stack (heap) is full. Then inserting an element would
    // lead to stack overflow
    if(!temp){
        printf("Heap overflow.\n");
        exit;
    }
    // initialize data into temp data field
    temp->data = data;
    if(top == NULL){
        top = temp;
        temp->next = NULL;// put NULL into temp next if top is equal to NULL
    }else{
        temp->next = top;// put top pointer reference into temp next
        top = temp;// make temp as top of Stack
    }
    return;
}
// Function to print all the
// elements of the stack
void traverse(struct stack* top){
    struct stack* p;
    // check for stack underflow
    if(top == NULL){
        printf("Stack is empty.\n");
        exit;
    }
    p = top;
    while(p!=NULL){
        printf("%d->",p->data);// print node data
        p = p->next;// assign temp link to temp
    }
}
void pop(){
    struct stack* p;
    // check if stack is empty
    if(is_empty()){
        printf("\nStack is empty,no data to show.\n");
    }else{
        p = top;// top assign into p
        printf("\nDequed %d.\n",p->data);
        top = p->next;
        p->next = NULL;// destroy connection between first and second
        free(p);
    }

}
// function to check if the stack is empty or not
int is_empty(){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}
// function to return top element in a stack
int peek(){
    if(is_empty()){
        return NULL;
    }else{
        return top->data;
    }
}
