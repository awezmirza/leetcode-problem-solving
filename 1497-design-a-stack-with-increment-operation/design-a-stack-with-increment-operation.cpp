class CustomStack {
public:
    vector<int> st;
    vector<int> inc;
    int ptr;
    int mx;
    CustomStack(int n) {
        st = vector<int>(n, 0);
        inc = vector<int>(n, 0);
        ptr = 0;
        mx = n;
    }
    
    void push(int x) {
        if (ptr < mx) {
            st[ptr] = x;
            ptr++;
        }
    }
    
    int pop() {
        if (ptr == 0) {
            return -1;
        }
        ptr--;
        if (inc[ptr] != 0) {
            st[ptr] += inc[ptr];
            if (ptr > 0) {
                inc[ptr - 1] += inc[ptr];
            }
            inc[ptr] = 0;
        }
        return st[ptr];
    }
    
    void increment(int k, int val) {
        if (ptr != 0) {
            int mini = min(k - 1, min(mx - 1, ptr - 1));
            inc[mini] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */