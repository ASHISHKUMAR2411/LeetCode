//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct Node{
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int x, int y){
        key = x;
        val = y;
        prev = NULL;
        next = NULL;
    }
};


class LRUCache
{
    private:
        unordered_map<int, Node*> mp;
        Node *head, *tail;
        list<Node*> dll;
        int capacity;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    void AddNode(int key, int val){
        Node *newNode = new Node(key, val);
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        
    }
    
    void DeleteNode(Node *ptr){
        Node *temp = ptr->prev;
        Node *temp2 = ptr->next;
        temp->next = temp2;
        temp2->prev = temp;
        delete ptr;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key) != mp.end()){
            AddNode(key, mp[key]->val);
            DeleteNode(mp[key]);
            mp[key] = head->next;
            return head->next->val;
        }
        else{
            return -1;
        }
        
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        if(mp.size() == capacity){
            if(mp.find(key) != mp.end()){
                mp[key]->val = value;
                DeleteNode(mp[key]);
                AddNode(key, value);
                mp[key] = head->next;
            }
            else{
                mp.erase(tail->prev->key);
                DeleteNode(tail->prev);
                AddNode(key, value);
                mp[key] = head->next;
            }
        }
        else{
            if(mp.find(key) != mp.end()){
                mp[key]->val = value;
                DeleteNode(mp[key]);
                AddNode(key, value);
                mp[key] = head->next;
            }
            else{
                AddNode(key, value);
                mp[key] = head->next;
            }
            
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends