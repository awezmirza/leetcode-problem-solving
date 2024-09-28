class MyCircularDeque {
public:
    vector<int> q;
    int frPtr;
    int backPtr;
    int size;
    int maxSize;

    MyCircularDeque(int k) {
        q = vector<int> (k, -1);
        frPtr = 0;
        backPtr = k - 1;
        size = 0;
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if (maxSize == size) {
            return false;
        }
        frPtr--;
        if (frPtr == -1) {
            frPtr = maxSize - 1;
        }
        q[frPtr] = value;

        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (maxSize == size) {
            return false;
        }
        backPtr++;
        if (backPtr == maxSize) {
            backPtr = 0;
        }
        q[backPtr] = value;

        size++;
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        frPtr++;
        if (frPtr == maxSize) {
            frPtr = 0;
        }

        size--;
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        backPtr--;
        if (backPtr == -1) {
            backPtr = maxSize - 1;
        }

        size--;
        return true;
    }
    
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return q[frPtr];
    }
    
    int getRear() {
        if (size == 0) {
            return -1;
        }
        
        return q[backPtr];
    }
    
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (maxSize == size) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */