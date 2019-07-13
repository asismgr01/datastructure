#include <stdio.h>
#include <stdlib.h>
struct node{
   int data;
   struct node *next;
}node;
struct node *head=NULL;
int createlinkedlist(int n);
void display(struct node *head);
int beginning(int b);
int nth(int m,int pos);
int del(int pos1);
void traverse();
void traverserecursive(struct node *head);
int length();
void reverse();
int reverserecursive(struct node *head);
void sort();
int main()
{
    int n,choice,b,exit,m,pos,pos1,len;
    do{
    printf("\n================LINKEDLIST====================");
    printf("\n1.Create linked list");
    printf("\n2.Insert node at beginning of linkedlist");
    printf("\n3.Insert node at nth position of linkedlist");
    printf("\n4.Delete node from linkedlist");
    printf("\n5.Display linkedlist");
    printf("\n6.Travarse linkedlist");
    printf("\n7.Find length of linkedlist");
    printf("\n8.Reverse linked list");
    printf("\n9.Sort Linked List");
    printf("\n10.Travarse linkedlist recursively");
    printf("\n11.Reverse linkedlist recursively");
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nHow many nodes you want in linkedlist: ");
            scanf("%d",&n);
            head=createlinkedlist(n);
            display(head);
           break;
        case 2:
            printf("\nEnter data for node: ");
            scanf("%d",&b);
            head=beginning(b);
            display(head);
           break;
        case 3:
            if(head==NULL){
                printf("\nLinkedlist is empty");
            }
            else{
            printf("\nEnter the position you want to add node: ");
            scanf("%d",&pos);
            printf("\nEnter the data for node: ");
            scanf("%d",&m);
            head=nth(m,pos);
            display(head);
            }
           break;
        case 4:
            if(head==NULL){
                printf("\nLinkedlist is empty,no nodes to delete.");
            }
            else{
            printf("\nEnter the position of the node you want delete: ");
            scanf("%d",&pos1);
            head=del(pos1);
            display(head);}
           break;
        case 5:
            if(head==NULL){
                 printf("\nLinkedlist is empty,no nodes to display.");
            }
            else{
              display(head);
            }
           break;
        case 6:
            traverse();
           break;
        case 7:
            len=length();
            if(len==0){
                printf("\nLinkedlist is empty.");
            }
            else{
                printf("\nLength of the linkedlist=%d",len);
            }
            break;
        case 8:
            reverse();
            break;
        case 9:
            sort();
            break;
        case 10:
            traverserecursive(head);
            break;
        case 11:
            head=reverserecursive(head);
            display(head);
            break;
        default:printf("\nInvalid number.");
        break;
    }
    printf("\n1 for continue,0 for exit: ");
    scanf("%d",&exit);
    }while(exit==1);
    return 0;
}
int createlinkedlist(int n){
    int i;
    struct node *temp;
    struct node *p;
    for(i=0;i<n;i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data for node: ");
        scanf("%d",&(temp->data));
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            p=head;
            while(p->next!=NULL){
                 p=p->next;
            }
            p->next=temp;
        }
    }
    return head;
}
void display(struct node *head){
    struct node *p=head;
    printf("|Head|%d|->",head);
    while(p!=NULL){
        printf("|%d|%d|->",p->data,p->next);
        p=p->next;
    }
}
int beginning(int b){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=b;
    temp->next=head;
    head=temp;
    return head;
}
int nth(int m,int pos){
    int count=1;
    struct node *p=head;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=m;
    while(count<(pos-1)){
        p=p->next;
        count++;
    }
    temp->next=p->next;
    p->next=temp;
    return head;
}
int del(int pos1){
    int count=1;
    struct node *p=head;
    struct node *t=head;
        while(count<(pos1-1)){
          p=p->next;
          count++;
        }
        while(count<=pos1){
          t=t->next;
          count++;
        }
        p->next=t->next;
    return head;
}
void traverse(){
    struct node *p=head;
    if(head==NULL){
        printf("\nNo data in linkedlist");
    }
    else{
        printf("Data in the linkedlist");
        while(p!=NULL){
           printf("\nData=%d",p->data);
           p=p->next;
       }
    }
}
int length(){
   int count=0;
   if(head==NULL){
      return 0;
   }
   else{
     struct node *p=head;
     while(p!=NULL){
        p=p->next;
        count++;
     }
     return count;
   }
}
void reverse(){
    int i=0,j,k,len,temp;
    len=length();
    j=len-1;
   struct node *ptr1=head;
   struct node *ptr2=head;
   if(head==NULL){
      printf("\nLinked list is empty, no nodes to reverse");
   }
   else{
        while(i<=j){
            k=0;
            while(k<j){
                ptr2=ptr2->next;
                k++;
            }
            temp=ptr1->data;
            ptr1->data=ptr2->data;
            ptr2->data=temp;
            i++;
            j--;
            ptr1=ptr1->next;
            ptr2=head;
        }
        display(head);
   }
}
void sort(){
    /*Selection sort in linked list.*/
    int i,j,k,len,temp;
    len=length();
    j=len-1;
    i=0;
   struct node *ptr1=head;
   struct node *ptr2=head;
   if(head==NULL){
     printf("\nLinked list is empty,no nodes to sort.");
   }
   else{
    while(i<j){
        k=i;/*k=0 rakhda inner loop every time suru bata start hunxa,so program
        crash vathyo. inner loop harek choti i bata j samma janu parne maile k=0 bata j samma garechu.*/
        while(k<j){
            ptr2=ptr2->next;
            if(ptr1->data>ptr2->data){/*swapping*/
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            k++;
        }
        ptr1=ptr1->next;
        ptr2=ptr1;
        i++;
    }
    display(head);
   }
}
void traverserecursive(struct node *head){
    if(head == NULL){
        printf("NULL");
    }
    else{
        printf("|%d|%d|->",head->data,head->next);
        traverserecursive(head->next);
    }
}
int reverserecursive(struct node *p){
    if(p->next == NULL){
        head = p;
        return;
    }
    else{
        reverserecursive(p->next);
        struct node *q=p->next;
        q->next=p;
        p->next=NULL;
    }
    return head;
}
