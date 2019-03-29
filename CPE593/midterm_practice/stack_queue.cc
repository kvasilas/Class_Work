class Stack{
private:
    GrowArray impl;
public:
    int pop(){ return impl.removeFirst(); }
    void push(int val){ impl.addFirst(); }
    bool isEmpty(){ return impl.isEmpty(); }
};

class queue{
private:
    LinkedList2 impl;
public:
    void enqueue(int val){ impl.addLast(val); }
    int dequeue(){ return impl.removeFirst(); }
    bool isEmpty(){ return imp.isEmpty() }
};
