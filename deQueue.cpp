#include<bits/stdc++.h>

class Queue {
  // Define the data members(if any) here.
  stack<int> input, output;

public:
  Queue() {
    // Initialize your data structure here.
  }

  void enQueue(int data) {
    // Implement the enqueue() function.
    // Pop out all elements from the stack input
    while (!input.empty()) {
      output.push(input.top());
      input.pop();
    }
    // Insert the desired element in the stack input 
    input.push(data);
    // Pop out elements from the stack output and push them into the stack input
    while (!output.empty()) {
      input.push(output.top());
      output.pop();
    }
  }

  int deQueue() {
    // Implement the dequeue() function.
    if (input.empty()) {
      return -1;
    }
    int val = input.top();
    input.pop();
    return val;
  }

  int peek() {
    // Implement the peek() function here.
    if (input.empty()) {
      return -1;
    }
    return input.top();
  }

  bool isEmpty() {
    // Implement the isEmpty() function here.
    return input.size()==0;
  }
};