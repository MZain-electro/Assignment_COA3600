
#include <stdio.h>
#include <stdlib.h>
 
// Node Definition 
typedef struct node {
    int data;
    int priority;
    struct node* next;
 
} Node;
 //Returns a newly created node
Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
 
    return temp;
}
 

void print(Node** head)
{
    printf("%d \n",(*head)->data);
}
 

void DeQueue(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
void push(Node** head, int d, int p)
{
    Node* start = (*head);
 
    // Create new Node
    Node* temp = newNode(d, p);
    if ((*head)->priority > p) {
 
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {
 
       
        while (start->next != NULL && start->next->priority < p) 
        {
            start = start->next;
        }
 
        temp->next = start->next;
        start->next = temp;
    }
}
 
int isEmpty(Node** head)
{
    return (*head) == NULL;
}
 
int main()
{//Randomly assume the queue to be 5,11,7,9,15=>
  
    Node* head = newNode(7, 2);
    push(&head, 11, 1);
    push(&head, 9, 3);
    push(&head, 5, 0);
    push(&head, 15, 4);
 
    while (!isEmpty(&head)) {
        print(&head);
        DeQueue(&head);
    }
 
    return 0;
}
