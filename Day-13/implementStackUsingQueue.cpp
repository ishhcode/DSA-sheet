//implementation Of stack using two queues
class Stack {
	// Define the data members.
    queue<int> q1;
    queue<int> q2;


   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q1.empty()){
            return true;
        }
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty()){
            return -1;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
};

// implementation of stack using single queue
class MyStack {
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }

    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
        
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        if(q.empty()){
            return 1;
        }
        return 0;
        
    }
};

