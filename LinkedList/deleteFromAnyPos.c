#include <stdio.h>
#include <stdlib.h>

typedef struct Node // structure definition
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL; // declaring the head pointer

void deleteFromAnyPos(int);
void display();

int main(void)
{
    deleteFromAnyPos(3);
    display(); 

    return 0;
}
void deleteFromAnyPos(int pos)
{
    if (!head)
        exit(1);

    if (pos < 0)
        exit(2);
    else
    {
        Node *temp1 = head;
        for (int i = 0; i < pos - 1; i++)
            temp1 = temp1 -> next;
        Node *temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        free(temp2);
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
