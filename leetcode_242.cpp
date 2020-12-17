// 242 有效的字母异位词
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 统计即可
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()) {
        return false;
      }
      vector<int> count(26, 0);
      for(int i = 0; i < s.size(); ++i) {
        ++count[s[i]-'a'];
        --count[t[i]-'a'];
      }
      for(auto i : count) {
        if(0 != i) {
          return false;
        }
      }
      return true;
    }
};