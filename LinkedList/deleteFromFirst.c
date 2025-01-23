#include <stdio.h>
#include <stdlib.h>

typedef struct Node // structure definition
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL; // declaring the head pointer

void deleteFromFirst();
void display();

int main(void)
{
    deleteFromFirst();
    display(); 

    return 0;
}

void deleteFromFirst()
{
    if (!head)
        exit(1);

    Node *temp = head;
    head = head -> next;
    free(temp);
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