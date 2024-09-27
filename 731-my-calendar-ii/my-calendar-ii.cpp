class MyCalendarTwo {
public:
    set<pair<int, int>> st;
    set<pair<int, int>> triple;

    bool book(int start, int end) {

        for (auto pr : triple) {
            int currSt = pr.first;
            int currEnd = pr.second;
            if (! (end <= currSt || start >= currEnd)) {
                return false;
            }
        }

        for (auto pr : st) {
            int currSt = pr.first;
            int currEnd = pr.second;
            if (! (end <= currSt || start >= currEnd)) {
                triple.insert({max(currSt, start), min(currEnd, end)});
            }
        }
        st.insert({start, end});
        return true;
    }
};


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */