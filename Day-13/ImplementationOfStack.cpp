//implementation of stack using array
// Stack class.
class Stack {
    int *arr;
    int size;
    int peek;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        peek = -1;
        size=capacity;
        arr = new int[size];

    }

    void push(int num) {
        // Write your code here.
        if(peek +1 == size){
            return;
        }
        peek++;
        arr[peek] = num;
    }

    int pop() {
        // Write your code here.
        if(peek== -1){
            return -1;
        }
        int x = arr[peek];
        peek--;
        return x;

    }
    
    int top() {
        // Write your code here.
        if(peek==-1){
            return -1;
        }
        return arr[peek];
    }
    
    int isEmpty() {
        // Write your code here.
        if(peek == -1){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(peek == size-1){
            return 1;
        }
        return 0;
    }
    
};