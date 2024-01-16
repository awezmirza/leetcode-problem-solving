class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> st;
    RandomizedSet() {}

    bool insert(int val) {
        if (st.find(val) == st.end()) {
            arr.push_back(val);
            st[val] = arr.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (st.find(val) == st.end()) {
            return false;
        }
        int pos = st[val];
        int lastEl = arr[arr.size() - 1];
        st[lastEl] = pos;
        arr[pos] = lastEl;
        st.erase(val);
        arr.pop_back();
        return true;
    }

    int getRandom() { return arr[rand() % arr.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */