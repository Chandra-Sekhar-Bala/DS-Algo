#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node()
    {
        value = 0;
        next = NULL;
    }
};


void  addtoEnd (node* &last){
    cout << "Enter The nuber" <<endl;
    int x;
    cin>> x;
    node * newNode = new node;
    newNode->value = x;
    if(!last)
    {
        last= newNode;
        newNode->next = last;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void CreateList(node* &last)
{
    cout << "How many numbers?"<<endl;
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    addtoEnd(last);
}

void addToBeg(node *&last)
{
    cout << "Enter The nuber" <<endl;
    int x;
    cin>> x;
    node *newNode = new node;
    newNode->value = x;
   if(!last)
    {
        last= newNode;
        newNode->next = last;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
}

void addToEmpty(node *&last)
{
    cout << "Enter The nuber" <<endl;
    int x;
    cin>> x;

    node *newNode = new node;
    newNode->value = x;
    last = newNode;
    newNode->next = last;
    cout << "New Node inserted at Empty List" << endl;

}
void addAfter(node *&last)
{
    
    cout << "Enter The nuber after you want to insert" << endl;
    int x;
    cin>> x;
    node* temp = last->next;
    do{
        if(temp->value == x)
        {
            cout << "Enter the Value" << endl;
            cin>> x;
            node * n = new node;
            n->value = x;
            n->next = temp->next;
            temp->next = n;
            return;
        }
    }while(temp!=last);
  cout << "Node not Found"<<endl;


}
void Display(node *last)
{
    if (!last)
    {
        cout << "Empy List" << endl;
        return;
    }
    node * temp = last->next;
    do
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    while (temp!=last->next);
}
void DeleteBeg(node* &last)
{
    if(!last){
        cout << "Empty" << endl;
        return;
    }
    if(last->next == last)
    {
        cout << "Deleted: " << last->value <<endl; 
        delete last;
        last = NULL;
    }
    node * t = last->next;
    last->next = t->next;
    cout << "Deleted: " << t->value <<endl; 
    delete t;
}
void deleteAtEnd(node* &last)
{
    if(!last){
        cout << "Empty" << endl;
        return;
    }
    if(last->next == last)
    {
        cout << "Deleted: " << last->value <<endl; 
        delete last;
        last = NULL;
    }

    node * t = last->next;

    while(t->next!= last)
    t = t->next;

    t->next = last->next;
    cout << "Deleted: " << last->value <<endl; 
    delete last;
    last = t;
    return;
}
int main()
{
    int ch;
    node * last=NULL;
    
    while (true)
    {
cout <<endl<<"1)CreateList 2)addToEmpty 3)addTobeg 4)addtoEnd 5)addAfter 6)Display 7)DeleteFromBeg 8)DeleteEnd  9)Exit ... " << endl<< endl;

        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1: CreateList(last); break;
        case 2: addToEmpty(last); break;
        case 3: addToBeg(last); break;
        case 4: addtoEnd(last); break;
        case 5: addAfter(last); break;
        case 6: Display(last); break;
        case 7: DeleteBeg(last); break;
        case 8: deleteAtEnd(last); break;
        case 9: cout << "Exit code 0"; return 0;
        default: cout << "Invalid choice" << endl;
        }

    }
    return 0;
}

