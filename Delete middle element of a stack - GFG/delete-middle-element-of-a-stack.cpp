//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMiddle(stack<int> &s, int deleteI, int count){
        if(s.size() == 0){
            return;
        }
        int val = s.top();
        s.pop();
        count++;
        deleteMiddle(s, deleteI, count);
        if(count != deleteI){
            s.push(val);
        }
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        // stack<int> q;
        // while (!s.empty()) {
        //     q.push(s.top());
        //     s.pop();
        // }
        int deleteI = ceil((float)(sizeOfStack + 1)/2);
        deleteMiddle(s, deleteI, 0);
        // s.clear();
        // while (!q.empty()) {
        //     s.push(q.top());
        //     q.pop();
        // }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends