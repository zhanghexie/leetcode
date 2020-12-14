// 232 用栈实现队列

# include<stack>
using namespace std;

class MyQueue {
  stack<int> in, out;

public:

    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
      in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      int2out();
      int x = out.top();
      out.pop();
      return x;
    }

    /** Get the front element. */
    int peek() {
      int2out();
      return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      return in.empty() && out.empty();
    }

    // 精华
    void int2out() {
      if (out.empty()){
        while(!in.empty()) {
          int x = in.top();
          in.pop();
          out.push(x);
        }
      }
    }
};