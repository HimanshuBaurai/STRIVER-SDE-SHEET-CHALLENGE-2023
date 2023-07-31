#include <bits/stdc++.h>
class Stack {
  // Define the data members.
  queue<int> q;

public:
  Stack() {
    // Implement the Constructor.
  }

  /*----------------- Public Functions of Stack -----------------*/

  int getSize() {
    // Implement the getSize() function.
    return q.size();
  }

  bool isEmpty() {
    // Implement the isEmpty() function.
    return q.size() == 0;
  }

  void push(int x) {
    // Implement the push() function.
    int s = q.size();
    q.push(x);
    for (int i = 0; i < s; i++) {

      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    // Implement the pop() function.
    if (isEmpty())
      return -1;
    int ans = q.front();
    q.pop();
    return ans;
  }

  int top() {
    // Implement the top() function.
    if (isEmpty())
      return -1;
    return q.front();
  }
};