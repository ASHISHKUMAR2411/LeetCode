//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends


void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size() < n){
	    return false;
	}
	else return true;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
	
}

int pop(stack<int>& s){
	// Your code goes here
	if(!isEmpty(s)){
	    int x = s.top();
	    s.pop();
	    return x;
	}
}

int getMin(stack<int>& s){
	// Your code goes here
	stack<int> s1;
	int mini = 1e9;
	while(!s.empty()){
	    mini = min(s.top(), mini);
	    s1.push(s.top());
	    s.pop();
	}
	while(!s1.empty()){
	    s.push(s1.top());
	    s1.pop();
	}
	return mini;
}