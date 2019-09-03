/*
  Stack implementation using array.
*/
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5/*This is macrow nothing but a constant*/
int top=-1;/*in stack operation is always done through top, default value of top is -1 because rightnow top
is not pointing to any index of stack[CAPACITY]*/
int stack[CAPACITY];
void push(int element);
int isFull();
int isEmpty();
void travarse();
int pop();
void peak();
int main()
{
    int element,opt,choice;
    do{
        printf("\n============Stack===============");
        printf("\n1.Push element into stack.");
        printf("\n2.Pop element from stack.");
        printf("\n3.Peek top element in stack.");
        printf("\n4.Is stack full.");
        printf("\n5.Is stack empty.");
        printf("\n6.Travarse stack.");
        printf("\nEnter choice: ");
        scanf("%d",&opt);
        switch(opt){
        case 1:
            printf("\nEnter number to push in stack: ");
            scanf("%d",&element);
            push(element);
        break;
        case 2:
            pop();
            printf("\nNow top is %d.",top);
        break;
        case 3:
            peak();
        break;
        case 4:
            /*full=isFull();*/
            if(isFull()==1){
                printf("\nStack is full.");
            }
            else{
                printf("\nStack is not full.");
            }
        break;
        case 5:
            if(isEmpty()==1){
                printf("\nStack is empty.");
            }
            else{
                printf("\nStack is not empty");
            }
        break;
        case 6:
            travarse();
            break;
        default:
            printf("\nInvalid number entered.");
            break;
        }
        printf("\n1 for continue, 0 for exit: ");
        scanf("%d",&choice);
    }while(choice==1);
    return 0;
}
void push(int element){
    if(isFull()){
        printf("\nStack is full, no space to push element.");
    }
    else{
        top++;/*default value of top is always -1,after increment top=0*/
        stack[top]=element;/*initializing value of element in stack[top(0)]*/
        printf("\n%d is pushed into the stack.",element);
    }
}
int isFull(){
    if(top==CAPACITY-1){/*CAPACITY is 5, so CAPACITY-1 is 4, if top is equal to CAPACITY-1
            that means stack[CAPACITY] is full.*/
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(top==-1){/*default value of top is always -1, if top==-1 that means top is not pointing to any index
            of stack[CAPACITY] which also means stack[CAPACITY] is empty.*/
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){
    int pop;
    if(isEmpty()){
       printf("\nNo elements in stack to pop.");
    }
    else{
        pop=stack[top];
        printf("\n%d poped from stack.",pop);
        top--;/*after decrement top is pointig to one less index than before. example:-if top was pointing on index 3
        of stack[CAPACITY] now after decrement top is pointing on index 2 of stack[CAPACITY].*/
        return top;
    }
}
void travarse(){
    int i;
   if(isEmpty()){
    printf("\nNo elements in stack to travarse.");
   }
   else{
     for(i=top;i>=0;i--){/*running loop from top to index 0 of stack[CAPACITY] to travarse all elements in
            stack[CAPACITY].*/
        printf("\nStack[%d]=%d",i,stack[i]);
     }
   }
}
void peak(){
    int peak;
   if(isEmpty()){
    printf("\nNo elements in stack to peek.");
   }
   else{
      peak=stack[top];/*in stack peak means returning top value of stack*/
      printf("\nTop element in stack is %d.",peak);
   }
}
