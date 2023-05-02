//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *odd = NULL, *even = NULL, *tempo = NULL, *tempe = NULL;
        Node *temp = head;
        while(temp){
            if(temp->data%2){
                if(odd == NULL){
                    odd = temp;
                    tempo = odd;
                    // tempo->next = NULL;
                }
                else{
                    tempo->next = temp;
                    tempo = tempo->next;
                    // tempo->next = NULL;
                }
            }
            else{
                if(even == NULL){
                    even = temp;
                    tempe = even;
                    // tempe->next = NULL;
                }
                else{
                    tempe->next = temp;
                    tempe = tempe->next;
                    // tempe->next = NULL;
                }
            }
            temp = temp->next;
        }
        if(tempe) tempe->next = NULL;
        if(tempo) tempo->next = NULL;
        if(even)
            head = even;
        else{
            head = odd;
        }
        while(even and even->next){
            even = even->next;
        }
        if(even)
            even->next = odd;
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends