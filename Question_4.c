
#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int data;
  struct Node* next;
};


// Print the linked list
void printList(struct Node* node) {
     int count=0;
   // printf("Printing Begining \n");
    struct Node* head=node;
    if(node==NULL)
    {
        printf("List is empty");
    }
   
    else{
  do{count=count+1;
//printf("address of the node %d is %d \n",count,node);
  printf(" %d \n ", node->data);
 // printf("value of the next node is %d \n",node->next);
  node = node->next;
  }while (node != head); 
  if(count==0)
  {printf("list is empty");}
   //printf("Printing End \n");
    }
  return;

}

void new_node(struct Node** head, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
struct Node* ptr,*temp;
ptr=*head;//copy contents of head to ptr
//printf("contents of head is %d \n",ptr);
  new_node->data = new_data;
  new_node->next = *head;
//printf("value of next is %d \n",new_node->next);

  if (*head == NULL) {
  *head = new_node;
  new_node->next = *head;
  //printf("address created for head is %d \n",new_node);
  return;
  }

  else{
 
  do{//printf("contents of ptr is %d \n",ptr);
  //temp=ptr;
  ptr=ptr->next;
      //printf("updated contents of ptr is %d \n",ptr);
  } while(ptr->next!=*head);

  //printf("New address is %d \n",new_node);
  //printf("contents of temp is %d \n",temp);
  ptr->next=new_node;
  }
 
}


void delete_first_node(struct Node** head)
{
    struct Node *previous = *head, *firstNode = *head;
 
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
 
    // check if list have single node
    // if yes then delete it and return
    if (previous->next == previous) {
        *head = NULL;
        return;
    }
 
    // traverse second node to first
    while (previous->next != *head) {
 
        previous = previous->next;
    }
 
    // now previous is last node and
    // first node(firstNode) link address
    // put in last node(previous) link
    previous->next = firstNode->next;
 
    // make second node as head node
    *head = previous->next;
    free(firstNode);
    return;
}


void delete_last_node(struct Node** head)
{ 
        if(*head==NULL)
    {
        printf("already empty");
    }
    else if ((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
        {
            //declare two temporary pointers
            struct Node *ptr1,*ptr2;
            ptr1=*head;
            
            ptr2=ptr1;
            while(ptr1->next!=NULL)
            {
                ptr2=ptr1;//saves the previous address 
               // printf("current address of ptr1 is %d and ptr 2 is %d ",ptr1,ptr2);
                ptr1=ptr1->next;
            }
            free(ptr1);
            ptr2->next=NULL;//last contents is null
        }
}


int count_nodes(struct Node* head)
{int count=0;
struct Node* temp=head;
if(head==NULL)
{
    printf("empty");
    return count;
}
    else{
        do {
             temp = temp->next;
    //printf("address of the node is %d \n",node);
    count=count+1;
    //printf("value of next is %d \n",node->next);
   
    }while(temp!=head);
    return count;
    }
}

void skip_head(struct Node **head,int position)
{for(int i=1;i<position;i++)
{
    *head=(*head)->next;
    
}
}


void delete_all(struct Node** head)
{//printf("value of head is %d",*head);
    int number_of_nodes=count_nodes(*head);
    printf("number of nodes is found to be %d \n",number_of_nodes);
    for(int i=0;i<number_of_nodes;i++)
    {
        delete_last_node(head);
        printf("number of nodes remaining %d \n",count_nodes(*head));

    }
    return;
}

int main() {
  struct Node* head = NULL;

//  new_node(&head, 3);
//  new_node(&head, 5);
// printList(head);

// new_node(&head, 7);
// printList(head);
// new_node(&head, 9);
// new_node(&head, 11);
// new_node(&head, 13);
//   printf("Linked list: ");
//   printList(head);
//   delete_first_node(&head);
//   printf("\n \n \n");
//   printList(head);
// skip_3(&head);
// printf("\n \n \n");
//   printList(head);


int number_of_persons,position;
printf("enter number of persons \n");
scanf("%d",&number_of_persons);
printf("enter position \n");
scanf("%d",&position);
     for(int i=1;i<=number_of_persons;i++)
     {
        new_node(&head,i);
     }
printList(head);
while(count_nodes(head)!=1)
{    skip_head(&head,position);
    delete_first_node(&head);
    printf("persons left \n");
    printList(head);
   
}
printf("last person left is \n");
printList(head);
}
