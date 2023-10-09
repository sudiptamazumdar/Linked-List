#include <stdio.h>
#include <stdlib.h>

typedef struct Node // structure definition
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL; // declaring the head pointer

void insertNodeAtBeginning(int);
void display();

int main(void)
{
    insertNodeAtBeginning(10);
    insertNodeAtBeginning(20);
    insertNodeAtBeginning(30);
    insertNodeAtBeginning(40);
    insertNodeAtBeginning(50);

    display(); // 50 40 30 20 10

    return 0;
}

void insertNodeAtBeginning(int data)
{
    Node *newNodePtr = malloc(sizeof(Node)); // creation of new node
    newNodePtr->data = data;                 // store data

    // insert at beginning
    newNodePtr->next = head;
    head = newNodePtr;
}

void display()
{
    Node *temp = head; // temp pointer to traverse the list

    while (NULL != temp) // while (temp)
    {
        printf("%d ", temp->data); // print the data
        temp = temp->next;         // update temp pointer
    }
}