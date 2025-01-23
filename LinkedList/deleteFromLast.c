#include <stdio.h>
#include <stdlib.h>

typedef struct Node // structure definition
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL; // declaring the head pointer
Node *tail = NULL; // declaring the tail pointer

void deleteFromLast();
void display();

int main(void)
{
    deleteFromLast();
    display(); 

    return 0;
}

void deleteFromLast()
{
    if (!head)
        exit(1);
   
    else
    {
        Node *temp = head;
        while (temp -> next != tail)
            temp = temp -> next;
        temp -> next = NULL;
        free(tail);
    }
}
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}