//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *zeros = NULL, *ones = NULL, *twos = NULL;
        Node *temp1 = NULL, *temp2 = NULL, *temp3 = NULL;
        Node *temp = head;
        while(temp){
            if(temp->data == 0){
                if(zeros == NULL){
                    zeros = temp;
                    temp1 = zeros;
                }
                else{
                    temp1->next = temp;
                    temp1 = temp1->next;
                }
            }
            if(temp->data == 1){
                if(ones == NULL){
                    ones = temp;
                    temp2 = ones;
                }
                else{
                    temp2->next = temp;
                    temp2 = temp2->next;
                }
            }
            if(temp->data == 2){
                if(twos == NULL){
                    twos = temp;
                    temp3 = twos;
                }
                else{
                    temp3->next = temp;
                    temp3 = temp3->next;
                }
            }
            temp = temp->next;
        }
        if(zeros){
            head = zeros;
            if(ones){
                temp1->next = ones;
                if(twos){
                    temp2->next = twos;
                    temp3->next = NULL;
                }
                else{
                    temp2->next = NULL;
                }
            }
            else if(twos){
                temp1->next = twos;
                temp3->next = NULL;
            }
            else{
                temp1->next = NULL;
            }
        }
        else if(ones){
            head = ones;
            if(twos){
                temp2->next = twos;
                temp3->next = NULL;
            }
            else{
                temp2->next = NULL;
            }
        }
        else{
            head = twos;
            temp3->next = NULL;
        }
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends