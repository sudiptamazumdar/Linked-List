#include <iostream>
using namespace std;

class Node
{
    public :
        int data;
        Node *next = nullptr;

        Node(int data)
        {
            this -> data = data;
        }
};

class Linkedlist
{
    public:
        Node *head = nullptr;
        Node *tail = nullptr;

        int countnode = 0;

        void insertAtFirst(int data)
        {
            Node *newnode = new Node(data);
            if (!head)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                newnode -> next = head;
                head = newnode;
            }
            countnode ++;
        }

    void insertAtEnd(int data)
    {
        Node *newnode = new Node(data);
        if (!head)
        {
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
        countnode++;
    }
    void insertAtAnyPos(int position, int data)
    {
        if (position < 0 || position > countnode)
            exit(1);
        else if(position == 0)
            insertAtFirst(data);
        else if(position == countnode)
            insertAtEnd(data);

        else
        {
            Node *newnode = new Node(data);
            Node *temp = head;
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp -> next;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode;
            
        }
        countnode++;
    }

    void deleteFromFirst()
    {
        if (!head)
            exit(1);

        if (countnode == 1)
            tail = nullptr;
        Node *temp = head;
        head = head -> next;

        delete temp;
        countnode--;
    }

    void deleteFromEnd()
    {
        if (!head)
            exit(1);

        if (countnode == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp -> next != tail)
            {
                temp = temp -> next;
            }
            temp -> next = nullptr;
            delete tail;
            tail = temp;
        }
        countnode--;

    }

    void deleteFromAnyPos(int position)
    {
        if (!head)
            exit(2);
        if (position < 0 || position > countnode - 1)
            exit(2);
        else if (position == 0)
            deleteFromFirst();
        else if (position = countnode - 1)
            deleteFromEnd();
        else
        {
            Node *temp1 = head;
            for (int i = 0; i < position - 1; i++)
            {
                temp1 = temp1 -> next;
            }
            Node *temp2 = temp1 -> next;
            temp1 -> next = temp2 -> next;
            delete temp2;
        }
        countnode--;
    }

    void display()
    {
        if (!head)
            exit(1);
        Node *temp = head;
        while(temp)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main()
{
    Linkedlist l1;
    l1.insertAtFirst(5); // 5
    l1.insertAtFirst(4); // 4 5
    l1.insertAtFirst(3); // 3 4 5
    l1.insertAtFirst(2); // 2 3 4 5
    l1.insertAtFirst(1); // 1 2 3 4 5

    l1.display(); // 1 2 3 4 5

    l1.deleteFromFirst(); // 2 3 4 5

    l1.display(); // 2 3 4 5

    l1.deleteFromEnd(); // 2 3 4

    l1.display(); // 2 3 4

    l1.deleteFromAnyPos(1); // 2 4

    l1.display(); // 2 4
    
    l1.deleteFromAnyPos(0); // 4

    l1.display(); // 4

    return 0;
}
