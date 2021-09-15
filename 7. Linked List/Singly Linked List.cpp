#include<iostream>
using namespace std;
class node{
	public:
	int n;
	node *next;

		node()
		{
		  n=0;
		  next = NULL;
		}

};
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
		temp->next = t;
	}

}
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
		while(t->next!=NULL)
		{

			t = t->next;
		}
		t->next=temp;	}
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
			temp = temp->next;
		}
		cout<<endl;
	}
}
void deleteAtTail(node* &head)
{
	node * temp = head;
	if(head == NULL){
	cout<<"Empty List "<<endl;
	return ;
	}
	else if(head->next->next==NULL)
	{
		delete(head->next);
		head = NULL;
	}
	else{
		while(head->next->next!=NULL)
		{
			head= head->next;
		}
		delete(head->next);
		head->next=NULL;
		head = temp;
	}
}
void deleteAtHead(node * &head)
{
	if(!head)
	return;
	else{
		node * temp = head;
		head = head->next;
		delete(temp);
	}
}
void deleteIth (node* &head , int n)
{
	if(head == NULL)
	{
		cout << "Empty List"<<endl;
		return;
	}
//	else if(head->next->next == NULL)
//	{
//	    delete(head->next)
//	     head = NULL;
//	     return;
//	}
	else {
		if(n==1)
		{
			deleteAtHead(head);
			return;
		}
		int ct =0;
		node *t,* temp = head;
		while(temp!= NULL && ct <  n-1  )
		{
			t = temp;
			ct++;
			temp = temp->next;
		}
		t->next = temp->next;
		delete (temp);
	}
}
int main()
{
	node* head = NULL;
	int n;
	while(1)
	{
	cout<<"<.......... 1:InsertAtTail  2:InsertAtHead  3:View  4:Delete-Head  5:Delete-Tail 6:Delete-i'th  7:Exit......../>"<<endl;
		cin >> n;
		switch(n){
		 case 1:{
				cout<<"Insert Value:"<<endl;
				cin >> n;
				insertAtTail(head,n);
				break;
			   }
			case 2:{
					cout<<"Insert Value:"<<endl;
				cin >> n;
				insertAtHead(head,n);
				break;
			}
		 case 3:viewList(head);
		    break;
 		case 4: deleteAtHead(head);
		    break;
		    case 5: deleteAtTail(head);
		    break;
		 case 6: cout<<"Which i'th Element Want to delete "<< endl;
		         cin >> n;
		         deleteIth(head,n);
		         break;
		case 7: return 0;
		 default:cout<<"Invalid click"<<endl;
		}
	}
	return 0;
}
