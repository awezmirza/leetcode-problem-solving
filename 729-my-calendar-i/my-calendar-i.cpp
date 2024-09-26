class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (auto pr : st) {
            int currSt = pr.first;
            int currEnd = pr.second;
            if (! (end <= currSt || start >= currEnd)) {
                return false;
            }
        }
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */