struct Node{
    int key, val;
    Node *next, *prev;
    Node(int x, int y){
        key = x, val = y, next = NULL, prev = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int size; 
    Node *head, *tail;
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }
    void addNode(int key, int val){
        Node *newNode = new Node(key, val);
        Node *temp = head->next;
        newNode->next = head->next;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node *ptr){
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        delete ptr;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            int val = mp[key]->val;
            deleteNode(mp[key]);
            addNode(key, val);
            mp[key] = head->next;
            return val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
       if(mp.size() == size){
            if(mp.find(key) != mp.end()){
                mp[key]->val = value;
                deleteNode(mp[key]);
                addNode(key, value);
                mp[key] = head->next;
            }
            else{
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addNode(key, value);
                mp[key] = head->next;
            }
        }
        else{
            if(mp.find(key) != mp.end()){
                mp[key]->val = value;
                deleteNode(mp[key]);
                addNode(key, value);
                mp[key] = head->next;
            }
            else{
                addNode(key, value);
                mp[key] = head->next;
            }
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */