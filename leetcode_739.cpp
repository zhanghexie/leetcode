// 739 每日温度

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
// 维持一个气温单调递减的栈。
// 每当遍历时，拿便利值依次与栈中值做比较。
// 代码实现1
class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      // 温度单调递减日期的栈
      stack<int> date;
      vector<int> ans(T.size(), 0);
      for(int i = 0; i < T.size(); ++i) {
        if(date.empty() || T[i] <= T[date.top()]) {
          date.push(i);
        }else{
          while(!date.empty() && T[i] > T[date.top()]) {
            int tmp = date.top();
            ans[tmp] = i - tmp;
            date.pop();
          }
          date.push(i);
        }
      }
      return ans;
    }
};
// 代码实现2
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      // 温度单调递减日期的栈
      stack<int> date;
      vector<int> ans(T.size(), 0);
      for(int i = 0; i < T.size(); ++i) {
        while(!date.empty()) {
          int pre_date = date.top();
          if(T[i] <= T[pre_date]){
            break;
          }
          date.pop();
          ans[pre_date] = i - pre_date;
        }
        date.push(i);
      }
      return ans;
    }
};