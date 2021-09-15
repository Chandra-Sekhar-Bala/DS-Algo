#include<iostream>
using namespace std;
class node{
	public:
	int n;
	node *p;

		node()
		{
		  n=0;
		  p = NULL;
		}

};
void insertAtTail(node* &head,int x)
{
	node* temp = new node;
	temp->n = x;
	if(!head)
	{
	head = temp;
	}
	else
	{
		node*  t = head;
		while(t->p!=NULL)
		{

			t = t->p;
		}
		t->p=temp;	}
}
void insertAtHead(node* &head, int x ){
	node* temp = new node;
	temp->n = x;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		node* t;
		t = head ;
		head = temp;
		temp->p = t;
	}

}


void viewList(node* head )
{
	if(head == NULL)
	cout<<"EMPTY "<<endl;
	else
	{
		node * temp = head;
		while(temp!=NULL)
		{
			cout<<temp->n<<"->";
			temp = temp->p;
		}
		cout<<endl;
	}
}

node* ReverseList(node* head)
{
	node* prev=NULL;
	node* curr = head;
	node* next = curr->p;
	
	if(head->p == NULL)
	{
		return head;
	}
	
	while(next!=NULL)
	{
		next= curr->p;
		
		curr->p=prev;
		
		
		prev=curr;
		curr = next;
		
	}
	
	return prev;	
	}

int main()
{
	node* head = NULL;
	int n;
//	while(1)
//	{
//	cout<<"<........ 1:InsertAtTail 2:InsertAtHead | 3:View  | 4:Exit  5: New Head ....../>"<<endl;
//		cin >> n;
//		switch(n){
//		 case 1:{
//				cout<<"Insert Value:"<<endl;
//				cin >> n;
//				insertAtTail(head,n);
//				break;
//			   }
//			case 2:{
//					cout<<"Insert Value:"<<endl;
//				cin >> n;
//				insertAtHead(head,n);
//				break;
//			}
//		 case 3:viewList(head);
//		     break;
//
//		 case 4: return 0;
//		 default:cout<<"Invalid click"<<endl;
//		}
//	}

insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
viewList(head);
node * newHead = ReverseList(head);
viewList(newHead);
// viewList(head);
insertAtTail(head,4);

	return 0;
}
