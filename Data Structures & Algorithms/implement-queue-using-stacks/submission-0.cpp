

#include <stack>
class MyQueue {
private:
  std::stack<int> f1;
  std::stack<int> f2;
  std::stack<int> f3;
  int top = 0;

public:
  MyQueue() {}

  void push(int x) {
    while (!f1.empty()) {
      f2.push(f1.top());
      f1.pop();
    }
    f2.push(x);
    while (!f2.empty()) {
      f1.push(f2.top());
      f2.pop();
    }
  }

  int pop() {
    int top = f1.top();
    f1.pop();
    return top;
  }

  int peek() { return f1.top(); }

  bool empty() { return f1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */