class NumArray {
public:

    void fillValues(vector<int>& segTree, vector<int>& nums, int st, int end, int pos) {
        if (st == end) {
            segTree[pos] = nums[st];
            return;
        }
        if (st > end) {
            return;
        }
        int mid = (st + end) / 2;
        fillValues(segTree, nums, st, mid, 2 * pos + 1);
        fillValues(segTree, nums, mid + 1, end, 2 * pos + 2);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2]; 
    }

    vector<int> segTree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree = vector<int> (4 * n, 0);
        fillValues(segTree, nums, 0, n - 1, 0);
    }

    void updateHelper(int st, int end, int pos, int index, int val) {
        if (st == end) {
            segTree[pos] = val;
            return;
        }
        if (st > end) {
            return;
        }
        int mid = (st + end) / 2;
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        if (index <= mid) {
            updateHelper(st, mid, left, index, val);
        } else {
            updateHelper(mid + 1, end, right, index, val);
        }
        segTree[pos] = segTree[left] + segTree[right]; 
    }
    
    void update(int index, int val) {
        updateHelper(0, n - 1, 0, index, val);
    }

    int sumRangeHelper(int left, int right, int st, int end, int pos) {
        if (st > right || end < left) {
            return 0;
        }
        if (st >= left && end <= right) {
            return segTree[pos];
        }

        int mid = (st + end)/2;
        return sumRangeHelper(left, right, st, mid, 2 * pos + 1) + sumRangeHelper(left, right, mid + 1, end, 2 * pos + 2);
    }  

    int sumRange(int left, int right) {
        return sumRangeHelper(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */