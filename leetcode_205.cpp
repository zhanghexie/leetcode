// 205 同构字符串

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // 将问题转化成第一次出现位置是否相同。
    bool isIsomorphic(string s, string t) {
      // 记录s和t中字符第一次出现的位置
      vector<int> sFirst(256,-1);
      vector<int> tFirst(256,-1);
      for(int i = 0; i < s.size(); ++i) {
        if(sFirst[s[i]] != tFirst[t[i]]) {
          return false;
        }
        sFirst[s[i]] = tFirst[t[i]] = i;
      }
      return true;
    }
};