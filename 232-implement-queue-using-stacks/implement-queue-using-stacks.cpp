class MyQueue {
public:
    stack<int>st;
    stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
    int front;
    while(!st.empty()){
        if(st.size() != 1){
            helper.push(st.top());
        } else {
            front = st.top(); // Store the front element
        }
        st.pop();
    }
    
    while(!helper.empty()){
        st.push(helper.top());
        helper.pop();
    }
    return front; // Return the front element
}

    
    int peek() {
        int ele=st.top();
        while(!st.empty()){
             ele=st.top();
            helper.push(st.top());
            st.pop();
        }

         while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return ele;
    }
    
    bool empty() {
        if(st.empty()){
            return true;
        }
        return false;
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