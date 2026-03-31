#include <algorithm>
#include <cstddef>
#include <iostream>

template <typename T> struct Link {
  T value;
  Link *next;
};

class MinStack {
  Link<int> *connection;
  stack<int> minTracker;

public:
  MinStack() : connection(nullptr) {};

  void push(int val) {
    Link<int> *newHead = new Link<int>{val, nullptr};
    if (connection == nullptr) {
      connection = newHead;
      minTracker.push(newHead->value);

    } else {
      newHead->next = connection;
      connection = newHead;

      // NOTE:
      if (newHead->value <= minTracker.top()) {
         minTracker.push(newHead->value);  
      }
    }
  }

  void pop() {
    if (connection != nullptr) {
      if (connection->value == minTracker.top()) {
        minTracker.pop();
      }
      connection = connection->next;
    }
  }

  int top() {
    if (connection != nullptr) {
      return connection->value;
    }

    return 0;
  }

  int getMin() { return minTracker.top(); }
};

