//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse_list(Node* head){
        Node *prev = NULL, *temp = head, *next = NULL;
        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(head == NULL) return NULL;
        head = reverse_list(head);
        int maxi = INT_MIN;
        Node *prev = NULL, *temp = head;
        while(temp){
            if(temp->data < maxi){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{ 
                maxi = max(maxi, temp->data);
                prev = temp;
                temp = temp->next;
            }
        }
        head = reverse_list(head);
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends