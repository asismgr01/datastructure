#include <stdio.h>
#include <stdlib.h>
struct doublell{
   int data;
   struct doublell *prev;
   struct doublell *next;
};
struct doublell *head=NULL;
int createdoublell(int num);
void display(struct doublell *head);
int insertbeg(int first);
int insertnth(int nth,int data);
int pop(int pos);
int len();
int reverse();
int selectionsort();
int main()
{
    int choice,n,num,first,beg,nth,data,insert,pos,remove,rev,sort;
    do{
    printf("\n=============Double Linked List=============");
    printf("\n1.Create double linked list.");
    printf("\n2.Insert node at beginning.");
    printf("\n3.Insert node at nth number.");
    printf("\n4.Delete node from double linked list.");
    printf("\n5.Display double linked list.");
    printf("\n6.Find length of double linked list.");
    printf("\n7.Reverse double linked list.");
    printf("\n8.Sort linked list.");
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nEnter the number of node: ");
            scanf("%d",&num);
            head=createdoublell(num);
            display(head);
        break;
        case 2:
            printf("\nEnter the number for first node: ");
            scanf("%d",&first);
            beg=insertbeg(first);
            if(beg==0){
               printf("\nCreate new list rather than adding node at beginning in empty list.");
            }
            else{
               display(beg);
            }
        break;
        case 3:
            printf("\nEnter position: ");
            scanf("%d",&nth);
            printf("\nEnter data: ");
            scanf("%d",&data);
            insert=insertnth(nth,data);
            if(insert==0){
                printf("\nWe cannot add node in nth number if list is empty.Please create new list.");
            }
            else{
               display(insert);
            }
        break;
        case 4:
            printf("\nEnter position of node you want to delete: ");
            scanf("%d",&pos);
            remove=pop(pos);
            if(remove==0){
                printf("\nWe cannot delete node from empty list.");
            }
            else{
                display(remove);
            }
            //printf("%d",remove);
        break;
        case 5:
            display(head);
        break;
        case 6:
            if(!len()){
                printf("\nList is empty,length list is 0.");
            }
            else{
                printf("\nLength of list is %d.",len());
            }
        break;
        case 7:
            rev=reverse();
            if(rev==0){
                printf("\nNo nodes in list to reverse.");
            }
            else{
                display(rev);
            }
        break;
        case 8:
            sort=selectionsort();
            if(sort==0){
                printf("\nList is empty,no nodes in list to sort.");
            }
            else{
                display(head);
            }
        break;
        default:
            printf("\nInvalid choice.");
            break;
    }
    printf("\nEnter 1 for continue 0 for exit: ");
    scanf("%d",&n);
    }while(n==1);
    return 0;
}
int createdoublell(int num){
    int i,data;
    struct doublell *p;
    /*p=head;(yaha p=head initialize garda if head!=NULL xa vane it works fine tara yedi head==NULL xa vane it throws an error after
      compiling because p=NULL initialize vayera baseko hunxa,ani jaba hamle naya node banayer head=temp garxam head ko value NULL bata
      change vayera temp ko address hunxa tara still p ko value chae NULL nai rahanxa so jaba line 75,76 ma p=p->next iterate garinxa
      program ma error auxa. */
    struct doublell *temp;
    for(i=0;i<num;i++){
       temp=(struct doublell*)malloc(sizeof(struct doublell));
       printf("\nEnter number for node: ");
       scanf("%d",&data);
       temp->data=data;
       temp->next=NULL;
       if(head==NULL){
        head=temp;
        temp->prev=NULL;
       }
       else{
         p=head;
         while(p->next!=NULL){
            p=p->next;
         }
         p->next=temp;
         temp->prev=p;
       }
    }
    return head;
}
void display(struct doublell *head){
    struct doublell *p=head;
    if(head==NULL){
        printf("\nList is empty, no nodes to display.");
    }
    else{
        printf("|Head|%d|->",head);
        while(p!=NULL){
            printf("<-|%d|%d|%d|->",p->prev,p->data,p->next);
            p=p->next;
        }
    }
}
int insertbeg(int first){
    struct doublell *temp;
    struct doublell *p;
    if(head==NULL){
        //printf("\nCreate new list rather than adding node at beginning in empty list.");
        return 0;
    }
    else{
        p=head;
        temp=(struct doublell*)malloc(sizeof(struct doublell));
        temp->data=first;
        temp->next=p;
        temp->prev=NULL;
        p->prev=temp;
        head=temp;
        return head;
    }
}
int insertnth(int nth,int data){
    int i=0;
    struct doublell *temp;
    struct doublell *temp1;
    struct doublell *p;
    if(head==NULL){
        return 0;
    }
    else{
        p=head;
        while(i<(nth-1)){
            p=p->next;
            i++;
        }
        temp=(struct doublell*)malloc(sizeof(struct doublell));
        temp->data=data;
        temp->next=p;
        temp1=p->prev;
        p->prev=temp;
        temp->prev=temp1;
        temp1->next=temp;
        return head;
    }
}
int pop(int pos){
    int i=0,length;
    struct doublell *p;
    if(head==NULL){
        return 0;
    }
    else{
        length=len();
        p=head;
        while(i<(pos-1)){
            p=p->next;
            i++;
        }
        p->next->prev=p->prev;
        p->prev->next=p->next;
        return head;
    }
}
int len(){
    int i=0;
    struct doublell *p;
    if(head==NULL){
        return 0;
    }
    else{
        p=head;
        while(p!=NULL){
            p=p->next;
            i++;
        }
        return i;
    }
}
int reverse(){
    int i=0,j=0,length,temp;
    length=len();
    struct doublell *p;
    struct doublell *q;
    if(head==NULL){
        return 0;
    }
    else{
        p=head;
        q=head;
        while(p->next!=NULL){
            p=p->next;
            i++;
        }
        while(j<length){
            temp=p->data;
            p->data=q->data;
            q->data=temp;
            p=p->prev;
            q=q->next;
            j++;
            length--;
        }
        return head;
    }
}
int selectionsort(){
    int temp,i=0,j,k,length;
    length=len();
    j=length-1;
    struct doublell *p;
    struct doublell *q;
   if(head==NULL){
    return 0;
   }
   else{
      p=head;
      q=head;
      while(i<j){
         k=i;
         while(k<j){
            q=q->next;
            if(p->data>q->data){//swapping
              temp=p->data;
              p->data=q->data;
              q->data=temp;
            }
            k++;
         }
         p=p->next;
         q=p;
         i++;
      }
    return head;
   }
}
