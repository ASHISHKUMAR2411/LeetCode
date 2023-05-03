//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
Node *reverse_list(Node *head){
    Node *curr = head, *temp = head, *prev = NULL;
    while(temp){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}
// your task is to complete this function
void sort(Node **H)
{
    if((*H)==NULL || (*H)->next==NULL)
        return ;
    Node *temp=*H;
    Node *odd = new Node(-1);
    Node *even = new Node(-1);
    Node *ROOT = new Node(-1);    
    Node *next_temp;
    Node *r1,*r2,*R;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(odd->data == -1)
            odd->data = temp->data,r1=odd;
        else
        {
            odd->next = temp;
            odd = odd->next;
        }
        temp = temp->next;
        next_temp=temp->next;
        
        if(even->data == -1)
            even->data = temp->data;
        else
        {
            temp->next = even;
            even = temp;
        }
        temp = next_temp;
    }
    if(temp!=NULL)
    {
        odd->next = temp;
        odd = odd->next;
    }
    odd->next=NULL,r2=even;
    
    while(r1!=NULL && r2!=NULL)
    {
        if(r1->data < r2->data)
        {
            if(ROOT->data == -1)
            {
                ROOT->data = r1->data,R=ROOT;
                r1=r1->next;
            }
            else
            {
                ROOT->next = r1;
                ROOT = ROOT->next;
                r1 = r1->next;
            }
        }
        else
        {
            if(ROOT->data == -1)
            {
                ROOT->data = r2->data,R=ROOT;
                r2=r2->next;
            }
            else
            {
                ROOT->next = r2;
                ROOT = ROOT->next;
                r2 = r2->next;
            }            
        }
    }
    
    while(r1!=NULL)
    {
        ROOT->next = r1;
        ROOT = ROOT->next;
        r1 = r1->next;
    }
    while(r2!=NULL)
    {
        ROOT->next = r2;
        ROOT = ROOT->next;
        r2 = r2->next;
    }
    *H=R;
     // Code here
    //  Node *sorted = NULL, *unsorted = NULL, *temps = NULL, *tempu = NULL;
    //  int count = 0;
    //  Node *temp = *head;
    // //  temp = temp->next;
    //  while(temp){
    //      if(count%2){
    //          if(unsorted == NULL){
    //              unsorted = temp;
    //              tempu = unsorted;
    //          }
    //          else{
    //              tempu->next = temp;
    //              tempu = tempu->next;
    //          }
    //      }
    //      else{
    //          if(sorted == NULL){
    //              sorted = temp;
    //              temps = sorted;
    //          }
    //          else{
    //          temps->next = temp;
    //          temps = temps->next;}
    //      }
    //      temp = temp->next;
    //      count++;
    //  }     
    //  if(tempu) tempu->next = NULL;
    //  if(temps) temps->next = NULL;
    //  if(unsorted){
    //      Node *t = reverse_list(unsorted);
    //      Node *head = NULL;
    //      while(sorted and unsorted){
             
    //      }
    //  }
    
}