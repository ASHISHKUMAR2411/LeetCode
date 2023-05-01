//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

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
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if(left == right) return head;
        if(head == NULL) return head;
        // ListNode *l = NULL, *r = NULL;
        Node *temp = head, *prev1 = NULL, *prev2 = NULL;
        int count = 1;
        while(temp){
            if(count == m - 1){
                prev1 = temp;
            }
            if(count == n){
                prev2 = temp;
                break;
            }
            count++;
            temp = temp->next;
        }
        
        Node *next = prev2->next, *head1 = NULL;
        prev2->next = NULL;
        if(prev1 == NULL) head1 = head;
        else head1 = prev1->next;
        
        // while(head1->next){
        //     cout << head1->val << " ";
        //     head1 = head1->next;
        // }
        head1 = reverse_list(head1);
        if(prev1 == NULL) head = head1;
        else prev1->next = head1;
        while(head1->next){
            // cout << head1->val << " ";
            head1 = head1->next;
        }
        // cout << head1->val << endl;
        head1->next = next;
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends