/*
Trees: Unlike Arrays, Linked Lists, Stack and queues, 
which are linear data structures, trees are hierarchical 
data structures.
Binary Tree: A tree whose elements have at most 2 children 
is called a binary tree. Since each element in a binary tree 
can have only 2 children, we typically name them the left 
and right child. 

Breath-first-traversal or Level-order-traversal from scratch.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *arr[10];/*array of pointers to store pointers(node of binary_tree) in queue format*/
int front = -1;/*front of queue*/
int rear = -1;/*rear of queue*/
/*structure of binary tree*/
struct binary_tree{
    int data;
    struct binary_tree* left;
    struct binary_tree* right;
};
struct binary_tree* newNode(int data);/*function to create new node in binary tree*/
struct binary_tree* head;/*head of binary tree*/
int main()
{
    head = newNode(1);/*test case*/
    head->left = newNode(3);
    head->right = newNode(2);
    head->left->left = newNode(4);
    head->left->right = newNode(6);
    head->right->left = newNode(8);
    head->right->right = newNode(7);
    breath_first_traversal(head);
    return 0;
}
/*function to create new node in binary tree*/
struct binary_tree* newNode(int data){
    struct binary_tree* node = (struct binary_tree*)malloc(sizeof(struct binary_tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
/*function to insert data in queue*/
void enqueue(struct binary_tree* p){
    if(front == -1){
        front++;
        rear++;
        arr[front] = p;
        //printf("\n%d in enqued on index %d.",p,front);
    }else{
        rear++;
        arr[rear] = p;
        //printf("\n%d in enqued on index %d.",p,rear);
    }
}
/*function to delete data from queue*/
void dequeue(){
    if(front == -1){
        printf("Queue is empty");
    }else{
        printf("%d,",*arr[front]);
        front++;
    }
}
/*function to find empty queue */
bool is_impty(){
    if(front && rear == -1){
        return true;
    }else{
        return false;
    }
}
/*function to traverse queue from front to rear*/
void traverse_queue(){
    int i = front, j = rear;
    for(i;i<=j;i++){
        printf("\narr[%d] = %d",i,arr[i]);
    }
}
/*function to traverse binary tree on level order*/
void breath_first_traversal(struct binary_tree* head){
    struct binary_tree* current = head;
    if(head == NULL){
        printf("Tree is empty.");/*if binary tree is empty*/
    }else{
        printf("Breath first or Level order traversal:-");
        enqueue(current);
        while(current!=NULL){
            if(current->left){
                enqueue(current->left);
            }
            if(current->right){
                enqueue(current->right);
            }
            dequeue();
            current = arr[front];
        }
    }
}
