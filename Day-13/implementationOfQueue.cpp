//implementation of queue using stacks
//in this solution the Time Complexity of push operation is O(1).
class Queue {
    // Define the data members(if any) here.
    stack<int>input,output;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        //T.C O(N)
        if(input.empty() && output.empty()) return -1;
        if(output.empty()){
            while(input.size()){
            output.push(input.top());
            input.pop();
        }

        } 
        int x= output.top();
        output.pop();
        return x;

    }

    int peek() {
        // Implement the peek() function here.
        if(input.empty() && output.empty()) return -1;
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (input.empty() && output.empty());
    }
};

//in this solution the Time Complexity of push operation is O(N).
#include <bits/stdc++.h>

using namespace std;

struct Queue {
  stack < int > input, output;
  
  // Push elements in queue
  void Push(int data) {
    // Pop out all elements from the stack input
    while (!input.empty()) {
      output.push(input.top());
      input.pop();
    }
    // Insert the desired element in the stack input
    cout << "The element pushed is " << data << endl;
    input.push(data);
    // Pop out elements from the stack output and push them into the stack input
    while (!output.empty()) {
      input.push(output.top());
      output.pop();
    }
  }
  // Pop the element from the Queue
  int Pop() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    int val = input.top();
    input.pop();
    return val;
  }
  // Return the Topmost element from the Queue
  int Top() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    return input.top();
  }
  // Return the size of the Queue
  int size() {
    return input.size();
  }
};