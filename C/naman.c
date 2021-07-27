#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(int value, struct node **head){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=(*head);
    *head=newnode;
}; //insert at beginning ka hai

void main(){


struct node *head, *newnode, *temp;
head=NULL;
int n;
printf("Enter the size of the array:\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("Enter the data:\n");
    scanf("%d",&newnode->data);
    if(head==0){
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}

temp=head;
while(temp!=0){
    printf("%d\n",temp->data);
    temp=temp->next;
}
printf("Ended\n");
insert(5,&head);

temp=head;
while(temp!=0){
    printf("%d\n",temp->data);
    temp=temp->next;
}

}