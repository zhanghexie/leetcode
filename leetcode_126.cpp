// 单词接龙II
# include<iostream>
# include<vector>
# include<map>
# include<unordered_set>
# include<unordered_map>
using namespace std;

// 把单词看作途中的节点，使用广度优先搜索构建出满足要就的路径最短的图，然后使用回溯算法找出全部路径。
class Solution1 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      vector<vector<string>> res; // 返回值
      unordered_set<string> dict; // 保存没有用到的单词
      for (const auto &w : wordList) {
        dict.insert(w);
      }
      // endWord没出现在里面就返回空
      if (!dict.count(endWord)) {
        return res;
      }

      dict.erase(beginWord);
      dict.erase(endWord);
    
      unordered_set<string> q1{beginWord}, q2{endWord}; // 从开头和结尾一起搜，q1始终是数量较少的方向对应的需要搜索的值
      unordered_map<string,vector<string>> next; // 键为当前字符串，值为与之只差一个字母的字符串向量
      
      bool q1Started = false; // 用来记录当前q1是否对应起始点开始搜索路径
      bool found = false; // 用来记录是q1和q2是否连起来
      
      // 开始广度优先搜索
      while(!q1.empty()) {    
        unordered_set<string> q; // 暂存
        // 搜索q1中每个值
        for (const auto &w: q1) {
          string s = w;
          // 通过每次改变s中一个字符找下一个值
          for (size_t i = 0; i < s.size(); ++i) {
            char ch = s[i];
            for (int j = 0; j < 26; ++j) {
              s[i] = j + 'a'; // s代表更改一个字母后的单词
              // 如果q2中找到s说明两个接上了
              if(q2.count(s)) {
                q1Started ? next[s].push_back(w): next[w].push_back(s);
                found = true;
              }
              // 没接上时
              if(dict.count(s)){
                q1Started ? next[s].push_back(w): next[w].push_back(s);
                q.insert(s);
              }
            }
            s[i] = ch; //更换为初始值 
          }
        }
        if(found) break; // 相交后直接退出
          // 删除dict中已经用过的元素
        for(auto &w : q){
            dict.erase(w);
        }

        // 让q1保存数量较少的。
        if(q.size() <= q2.size()){
            q1 = q;
          } else {
            q1 = q2;
            q2 = q;
            q1Started = !q1Started;
          }
      } 

      if(found){
        vector<string> path = {beginWord};
        backtracking(beginWord, endWord, next, path, res);
      }
      return res;
    }

    // 回溯算法找到全部路径
    void backtracking(const string &src, const string &dst, unordered_map<string,vector<string>> &next, vector<string> &path, vector<vector<string>> &res){
      // 如果起始字符串与目标字符串相同则说明找到了。
      if(src == dst) {
        res.push_back(path);
        return;
      }

      for(const auto &s : next[src]) {
        path.push_back(s);
        backtracking(s, dst, next, path, res);
        path.pop_back();
      }
    }
};