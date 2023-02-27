#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *newnode = new Node(d);
        head = newnode;
    }
    else
    {
        Node *newnode = new Node(d);

        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtTail(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *newnode = new Node(d);
        head = newnode;
    }
    else
    {
        Node *newnode = new Node(d);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertAtPosition(Node *&head, int d, int pos)
{
    if (head == NULL)
    {
        Node *newnode = new Node(d);
        head = newnode;
    }
    else
    {
        if (pos == 1)
        {
            insertAtHead(head, d);
        }
        else
        {

            Node *newnode = new Node(d);
            Node *temp = head;
            int count = 1;

            while (count < pos - 1)
            {
                temp = temp->next;
                count++;
            }

            if (temp->next == NULL)
            {
                insertAtTail(head, d);
            }
            else
            {
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next->prev = newnode;
                temp->next = newnode;
            }
        }
    }
}

void deleteHead(Node *&head)
{
    Node *temp = head;

    head = head->next;
    head->prev = NULL;

    free(temp);
}

void deleteTail(Node *&head)
{
    Node *temp = head;
    Node *current = head;

    while (temp->next != NULL)
    {
        current = temp;
        temp = temp->next;
    }
    current->next = NULL;
    free(temp);
}

void deletePosition(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteHead(head);
    }
    else
    {
        Node *temp = head;
        Node *current = head;
        int count = 1;

        while (count < pos)
        {
            current = temp;
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            deleteTail(head);
        }
        else
        {
            current->next = temp->next;
            temp->next->prev = current;
            free(temp);
        }
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node = new Node(20);
    cout << node->data << endl;
    cout << node->next << endl;
    cout << node->prev << endl;

    Node *head = node;

    print(head);

    insertAtHead(head, 10);
    insertAtHead(head, 35);
    insertAtHead(head, 30);

    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);

    insertAtPosition(head, 15, 8);
    insertAtPosition(head, 5, 1);
    insertAtPosition(head, 25, 5);

    print(head);

    deleteHead(head);
    deleteTail(head);
    deletePosition(head, 8);
    deletePosition(head, 1);
    deletePosition(head, 3);

    print(head);

    return 0;
}