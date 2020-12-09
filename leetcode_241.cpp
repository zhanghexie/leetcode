// 241.为运算表达式设计优先级
#include <iostream>
#include <vector>
using namespace std;

// 采用分治思想，不要被题目中所说的括号束缚住，函数的作用就是计算在不考虑优先级的情况下表达式所有可能的值。
// 该算法的本质是对所有的情况构成的空间，以某一个符号优先级是否是最小进行划分。
class Solution1 {
public:
    vector<int> diffWaysToCompute(string input) {
      vector<int> res;
      for (int i = 0; i<input.size(); ++i) {
        char c = input[i];
        if (c == '+' || c =='-' || c == '*' ) {
          // 对与出现的符号，假设其优先级是最小的，就能将该问题划分为两个子问题。
          vector<int> left = diffWaysToCompute(input.substr(0,i));
          vector<int> right = diffWaysToCompute(input.substr(i+1));
          for (const int & l : left) {
            for (const int & r : right) {
              switch (c) {
                case '+' : res.push_back(l+r); break;
                case '-' : res.push_back(l-r); break;
                case '*' : res.push_back(l*r); break;
              }
            }
          }
        }
      }
      // 边界情况，仅有一个字符。
      if(res.empty()) res.push_back(stoi(input));
      return res;
    }
};
