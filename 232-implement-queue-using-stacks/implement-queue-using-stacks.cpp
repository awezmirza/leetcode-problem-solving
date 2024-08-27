class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        if (s1.empty() && s2.empty()) {
            s1.push(x);
        } else {
            s2.push(x);
        }
    }
    
    int pop() {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()) {
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