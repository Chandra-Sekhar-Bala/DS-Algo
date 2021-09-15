#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node()
    {
        data =0;
        next = NULL;
    }
};

void insert(node *& head, int num){
    node * n = new node;
    n->data = num;
    if(!head)
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node * head)
{
    if(!head)
    return;

    node * t = head;
    while(t)
    {
        cout << t->data << "->";
        t= t->next;
    }
}

void addAtLL(node * head1, node * head2,int num){
   
    while(--num)
    head1= head1->next;

    while(head2->next)
    head2 = head2->next;

    head2->next = head1;

}

int size (node * head){
    int ct =0;
    while(head)
    {
        ct++;
        head = head->next;
    }

    return ct;
}
int connect (node* head1,node *head2)
{
    int l1 = size(head1);
    int l2 = size(head2);
    int ct;
    if(l1 > l2)
    {
        ct = l1 -l2;
        while(ct--)
        head1 = head1->next;
    }
    else{
        ct = l2 -l1;
         while(ct--)
        head2 = head2->next;
    }
    while(head1  && head2)
    {
        if(head1 == head2)
        return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;

}
int main()
{
    node * head1 = NULL;
    node * head2 = NULL;
    insert(head1,1);
    insert(head1,2);
    insert(head1,3);

    display(head1);

    insert(head2,8);
    insert(head2,9);
    insert(head2,10);

    cout << endl;

    display(head2);
    
    cout << endl;
    addAtLL(head1,head2,2);
    display(head2);
    cout << endl;

    cout<<connect(head1,head2)<<endl;

}