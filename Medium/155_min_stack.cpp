class MinStack {
public:
    stack<int> sta;
    stack<int> sta1; // If the push val is smaller than sta1.top(), push it. Or push the larger val into sta2; What's more, the first val must be put into the sta1 to become the sta1.top() comparing value. If there is any each val smaller than the first value in sta1.
    // It means that unless pop out all the value in sta2, the smallest value is still in sta1.top().
    stack<int> sta2; // In each time slot, sta2 stores any value that is larger than sta1.top(). If sta1.top() becomes smaller, the criterion for comparison also updates accordingly.
    // priority_queue<int, vector<int>, greater<int>> pq;
    MinStack() {
        
    }
    
    void push(int val) {
        sta.push(val);
        if(sta1.empty()){
            sta1.push(val);
        }else if(!sta1.empty() && sta2.empty())
        {
            if(val <= sta1.top())
            {
                sta1.push(val);
            }else{
                sta2.push(val);
            }
        }
        else if(!sta1.empty() && !sta2.empty()){
            if(val <= sta1.top())
            {
                sta1.push(val);
            }else{
                sta2.push(val);
            }
        }
        return;
    }
    
    void pop() {
        int temp = sta.top();

        // chekc which stack have the sta.top();
        if(temp == sta1.top())
        {
            sta1.pop();
        }else if(temp == sta2.top())
        {
            sta2.pop();
        }
        // pop out the normal stack;
        sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        
        return sta1.top();
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
