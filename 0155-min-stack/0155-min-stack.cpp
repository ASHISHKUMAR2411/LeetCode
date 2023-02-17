class MinStack {
public:
    vector<pair<int, int>> v;
    MinStack() {
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val, val});
        }
        else{
            v.push_back({val, min(val, v.back().second)});
        }
    }
    
    void pop() {
        if(v.empty()){
           return;
        } 
        else{
            v.pop_back();
        }
    }
    
    int top() {
        if(v.empty()) return -1;
        else{
            return v.back().first;
        }
    }
    
    int getMin() {
        if(v.empty()) return -1;
        else return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */