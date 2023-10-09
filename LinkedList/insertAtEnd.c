#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertAtLast(int data)
{
    Node *newnode = malloc(sizeof(Node)); 
    newnode -> data = data;
    newnode -> next = NULL;
    if (NULL == head)
    {
        head = newnode;
    } 
    else
    {
        Node *t = head;
        while (NULL != t -> next)
        {
            t = t -> next;
        }
        t -> next = newnode;
    }
    
}

void display()
{
    Node *temp = head;
    while (NULL != temp)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

int main()
{
    insertAtLast(2);
    insertAtLast(4);
    insertAtLast(6);
    insertAtLast(8);
    insertAtLast(10);

    display();
    return 0;
}