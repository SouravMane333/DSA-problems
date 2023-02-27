#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        Node *newnode = new Node(d);
        Node *current = tail;

        while (current->data != element)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        Node *temp = tail;
        Node *current = temp->next;

        while (current->data != value)
        {
            temp = current;
            current = current->next;
        }

        temp->next = current->next;

        if (current == temp)
        {
            tail = NULL;
        }
        else if (tail == current)
        {
            tail = temp;
        }
        free(current);
    }
}

void print(Node *&tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        do
        {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != temp);
        cout << endl;
    }
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 10);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    insertNode(tail, 10, 15);
    print(tail);

    insertNode(tail, 15, 25);
    print(tail);

    insertNode(tail, 25, 5);
    print(tail);

    insertNode(tail, 5, 35);
    print(tail);

    insertNode(tail, 35, 20);
    print(tail);

    deleteNode(tail, 25);
    print(tail);

    return 0;
}