/*
A Binary Search Tree is a type of binary tree data structure in which 
the nodes are arranged in order, hence also called as “ordered binary 
tree”. It’s a node-based data structure which provides an efficient and 
fast way of sorting, retrieving, searching data. For each node, the 
elements in the left subtree must be less than or equal to the key in 
its parent node (L<P), and the elements in the right subtree must be 
greater than or equal to the key in its parent node (R>P). There should 
be no duplicate keys. In simple terms, it’s a special kind of binary tree 
data structure that efficiently stores and manages items in memory.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*structure of the node*/
struct binary_search_tree{
    int data;
    struct binary_search_tree* left;
    struct binary_search_tree* right;
};
struct binary_search_tree* head;/*head(root) of binary search tree*/
struct binary_search_tree* newNode(int data);/*function to create new node*/
struct binary_search_tree* insert(struct binary_search_tree* head,int data);/*function to insert
data in binary search tree order*/
int main()
{
    head = insert(head,8);
    insert(head,2);
    insert(head,5);
    insert(head,11);
    insert(head,13);
    insert(head,17);
    /*
               8
             /   \
            2    11
           / \   /  \
        NULL  5 NULL 13
                    /  \
                  NULL 17
                       / \
                    NULL NULL                  
    */
    //breath_first_traversal(head);
    return 0;
}
/*function to create new node*/
struct binary_search_tree* newNode(int data){
    struct binary_search_tree* temp = (struct binary_search_tree*)malloc(sizeof(struct binary_search_tree));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/*function to insert data in binary search tree order*/
struct binary_search_tree* insert(struct binary_search_tree* head,int data){
    struct binary_search_tree* x;
    struct binary_search_tree* y;
    struct binary_search_tree* temp;
    temp = newNode(data);
    if(head == NULL){
        head = temp;
        printf("%d is head node.",head);
        return head;
    }else{
        x = head;
        y = NULL;
        while(x != NULL){
            y = x;
            if(x->data > data){
                x = x->left;
            }else{
                x = x->right;
            }
        }
        if(y->data > data){
            y->left = temp;
        }else{
            y->right = temp;
        }
    }
    return y;
}
/*function to traverse binary search tree(breath first search)*/
/*
void breath_first_traversal(struct binary_search_tree* head){
    struct binary_search_tree* current;
    if(head == NULL){
        printf("\nTree is empty.");
    }
    else{
        printf("\nBreath first traversal:- ");
        current = head;
        inQueue(current);
        while(!isEmpty()){
            if(current->left != NULL){
                inQueue(current->left);
            }
            if(current->right != NULL){
                inQueue(current->right);
            }
            deQueue();
            current = queue[front];
        }
    }
}
*/