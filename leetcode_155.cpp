// 155 最小栈

# include<stack>
using namespace std;
class MinStack {
  stack<int> s, minVaule;
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
      // 确保在x压入栈时，当前栈中的虽小值，已经被压入栈中，注意等号一定要有。
      if(minVaule.empty() || minVaule.top() >= x) minVaule.push(x);
      s.push(x);
    }

    void pop() {
      // 有最小值出栈时，同样将minValue中的值弹出。
      if(!minVaule.empty() && s.top() == minVaule.top()) minVaule.pop();
      s.pop();
    }

    int top() {
      return s.top();
    }

    int getMin() {
      return minVaule.top();
    }
};
