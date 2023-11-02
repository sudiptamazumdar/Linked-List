#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int data, int n)
{
    Node *newnode = malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = NULL;
    if (n == 1)
    {
        newnode -> next = head;
        head = newnode ;
        return;
    }
    Node *temp2 = head;
    for (int i = 1; i < n-1; i++)
    {
        
        temp2 = temp2 -> next;
    }
    newnode -> next = temp2 -> next;
    temp2 -> next = newnode;
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
int main()
{
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    display();
    return 0;
}