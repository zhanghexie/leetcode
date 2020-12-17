//696 计数二进制子串
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 用字符串结尾来表示一个子字符串。
// 统计从这个结尾往处前数连续的与相值相同的字符串的个数cur以及之前连续的与结尾值不同字符的个数pre。
// 如果pre>=cur，那么以这个字符串结尾的字符串就满足要求。

class Solution {
public:
    int countBinarySubstrings(string s) {
      // cur表示当前位置及之前，与当前位置值相同的连续字符的值的个数。
      // pre表示当前位置之前，与当前值不同的值的个数。
      int pre = 0, cur = 1, ans = 0;
      for(int i = 1; i < s.size(); ++i) {
        if(s[i] == s[i-1]){
          ++cur;
        }else{
          pre = cur;
          cur = 1;
        }
        if(pre >= cur){
          ++ans;
        }
      }
      return ans;
    }
};
