#include<stdio.h>
#include<stdlib.h>


 struct node{


         int data;


        struct node *next;};


struct node *head, *newnode,
*temp;


void create_singlylinkedlist()


{


           head=NULL;


        int ch=1;


        while(ch)


        {


        newnode=(struct node
*)malloc(sizeof(struct node));


        printf("Enter data--->");


        scanf("%d",&newnode->data);


        newnode->next=NULL;


        if (head==NULL){


            head=newnode;


            temp=head;


        }


        else {


            temp=head;


            while(temp->next!=NULL)


            {


                temp=temp->next;


            }


            temp->next=newnode;


        }


        printf("\nEnter more data(1/0)       ");


        scanf("%d",&ch);


        }


 


}


void delete_at_beginning()


{


temp=head;


printf("Element deleted----%d",temp->data);


head=head->next;


free(temp);


 


}


void delete_at_end()


{


   
struct node *prevnode;


   
temp=head;


            while(temp->next!=NULL)


            {


                prevnode=temp;


                temp=temp->next;


            }


     printf("Element deleted----%d",temp->data);


            if (temp==head)


{


   
head=NULL;


  
}


else{


   
prevnode->next=NULL;


}


free(temp);


}


 


 


void display_linkedlist()


{


 


 printf("\nPrint Display the element of Singly List---  ");


        temp=head;


        while(temp!=NULL)


        {


            printf("%d\t",temp->data);


            temp=temp->next;


        }


}


void delete_at_anyposition()


{ int count=0,n,i=1;


 struct node *nextnode;


 temp=head;


            while(temp->next!=NULL)


            {


                temp=temp->next;


                count++;


            }


            printf("\nEnter the position where yu wish to Delete the data..");


            scanf("%d",&n);


 


            if (n>count)


                printf("\nWrong position...");


            else{


             if (count==1)


                {nextnode=head;


                head=NULL;}


            else{


            temp=head;


            while(i<n-1){


                temp=temp->next;


                i++;}


                nextnode=temp->next;


               
temp->next=nextnode->next;


                           }


            }


            free(nextnode);


}


int main()


{


   
int t=1,opt;


   
do{


   
printf("-----------Enter MAIN MENU-------\n");


   
printf("1.   Create Linked List\n");


   
printf("2.    Delete the element in the beginning\n");


   
printf("3.    Delete the element in the end\n");


   
printf("4.    Delete the element at any position\n");


   
printf("5.     Display the entire element in the linked list\n");


   
printf("6.     Exit");


   
printf("\nEnter the option 1 2 3 4 5 6-------------> ");


   
scanf("%d", &opt);


   
switch(opt) {


        case 1:create_singlylinkedlist();break;


        case 2:delete_at_beginning();break;


        case 3:delete_at_end();break;


        case 4:delete_at_anyposition();break;


        case 5:display_linkedlist();break;


        case 6:t=0;break;


        default: printf("\nWRONG OPTION");


   
}


   
}while (t==1);


      return 0;


}