#include <stack>

class MyQueue {
public:

    stack<int> first;
    stack<int> second;

    MyQueue() {
    
        
    }
    
    void push(int x) {
        first.push(x);
    }
    
    //we need to remove the first element that is waiting
    int pop() {
       if(second.size()==0){
        move();
       }
       int tempt = second.top();
       second.pop();
        return tempt;
    }
    
    //we need to check who is waiting in the front of the que
    int peek() {
        if(second.size()==0){
        move();
       }
        return second.top();
    }
    
    bool empty() {
        return first.empty() and second.empty();
    }

    void move() {
        while (!first.empty()){
            second.push(first.top());
            first.pop();
        }
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