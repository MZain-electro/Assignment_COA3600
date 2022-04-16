
#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int data;
  struct Node* next;
};


// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
//printf("address of the node is %d \n",node);
  printf(" %d \n ", node->data);
  //printf("value of next is %d \n",node->next);
  node = node->next;
  }
}

void new_node(struct Node** head, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
struct Node* ptr;
ptr=*head;//copy contents of head to ptr
printf("contents of head is %d \n",ptr);
  new_node->data = new_data;
  new_node->next = NULL;

  if (*head == NULL) {
  *head = new_node;
  printf("address created for head is %d \n",new_node);
  return;
  }

  else{
  while(ptr->next!=NULL)
  {//printf("contents of ptr is %d \n",ptr);
      ptr=ptr->next;
  }
  printf("New address is %d \n",new_node);
  ptr->next=new_node;
  }
 
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


int main() {
  struct Node* head = NULL;

 new_node(&head, 3);
 printf("new node insertion \n");
 new_node(&head, 5);
 new_node(&head, 7);
 new_node(&head, 9);
  printf("Linked list: ");
  printList(head);
  delete_last_node(&head);
  printf("Linked list after deletion: ");
    printList(head);

}
