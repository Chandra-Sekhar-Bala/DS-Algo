#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *prev;
    node *next;
    node()
    {
        value = 0;
        prev = NULL;
        next = NULL;
    }
};

// Taking head's reference onlz bcz of if hedd is null we have to point it to a newNode:
void insertAtTail(node *&head, int n)
{
    node *newNode = new node;
    newNode->value = n;
    if (!head)
    {
        head = newNode;
        return;
    }
    // We've values in LL
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtHead(node *&head, int n)
{
    node *newNode = new node;
    newNode->value = n;
    if (!head)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void addAfter(node *head, int n)
{
    node *newNode = new node;
    newNode->value = n;
    if (!head)
    {
        head = newNode;
        return;
    }

    newNode->next = head->next;
    newNode->prev = head;
    head->next = newNode;
    newNode->next->prev= newNode;

}
void ShowList(node *head)
{
    if (!head)
    {
        cout << "Empy List" << endl;
        return;
    }

    while (head != NULL)
    {
        cout << head->value << "->";
        head = head->next;
    }
}


int main()
{
    node *head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    //  ShowList(head);
    insertAtHead(head, 1);
    // ShowList(head);
    addAfter(head,99);
    addAfter(head,90);
    addAfter(head,9);
    ShowList(head);
    return 0;

}


