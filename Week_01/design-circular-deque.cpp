class MyCircularDeque {
private:
    vector<int> arr;
    int k, front, rear, len = 0;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): arr(k, 0), len(0), k(k), front(k - 1), rear(0) {
        // front 和 rear 两根指针分别标记着前和后，并不是真的按照队头队尾插入的
        // [0, 0, 0, 0, 0] k = 5
        //  r 👉    👈 f
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (len == k) return false;
        arr[front] = value;
        // update front
        front = (front - 1 + k) % k;
        len++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (len == k) return false;
        arr[rear] = value;
        // update rear
        rear = (rear + 1) % k;
        len++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % k;
        len--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + k) % k;
        len--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return arr[(front + 1) % k];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return arr[(rear - 1 + k) % k];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return len == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return len == k;
    }
};
