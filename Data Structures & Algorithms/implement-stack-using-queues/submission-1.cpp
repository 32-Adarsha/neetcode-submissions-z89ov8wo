

#include <queue>
class MyStack {
private:
  std::queue<int> first;
  std::queue<int> second;
  int top_ = 0;

public:
  MyStack() {}

  void push(int x) {
    first.push(x);
    top_ = x;
  }

  int pop() {
    int last_top = top_;
    while (first.size() > 1) {
      top_ = first.front();
      second.push(first.front());
      first.pop();
    }

    if (first.size() > 0)
      first.pop();

    first = second;
    second = {};

    return last_top;
  }

  int top() { return top_; }

  bool empty() { return first.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */