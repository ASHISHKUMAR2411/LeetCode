class MyQueue {
public:
    stack<int> in, ou;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int x = peek();
        ou.pop();
        return x;
    }
    
    int peek() {
        if(ou.empty()){
            while(in.size()){
                ou.push(in.top());
                in.pop();
            }
        }
        if(!ou.empty())
            return ou.top();
        else return -1;
    }
    
    bool empty() {
        return in.empty() && ou.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */