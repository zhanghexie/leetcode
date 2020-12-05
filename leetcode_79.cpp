// 79搜索单词
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
 public:
  vector<int> direction = {-1, 0, 1, 0, -1};
  bool exist(vector<vector<char>> &board, string word) {
    // 边界条件
    if (word.empty()) return false;

    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    bool res = false;

    // 主循环，依次遍历
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        bc(board, visited, word, i, j, 0, res);
        if (res) break;
      }
    }

    return res;
  }

  void bc(vector<vector<char>> &board, vector<vector<bool>> &visited,
          string &word, int x, int y, int pos, bool &res) {
    // 索引越界直接返回。
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
      return;
    }

    // 已经找到或访问过或者不等直接返回，加上res不然会超时。
    if (res || visited[x][y] || board[x][y] != word[pos]) {
      return;
    }

    // 一旦查到访问完直接返回结果。
    if (pos == word.size() - 1) {
      res = true;
      return;
    }

    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
      int i = x + direction[d], j = y + direction[d + 1];
      bc(board, visited, word, i, j, pos + 1, res);
    }
    visited[x][y] = false;
  }
};