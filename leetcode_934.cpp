// 934 最短的桥
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 深度优先算法找出第一个桥，从第一个桥出发广度优先算法找第二个。
class Solution1 {
  vector<int> direction{-1, 0, 1, 0, -1};

 public:
  int shortestBridge(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    queue<pair<int, int>> points;

    bool flipped = false;  // 因为break无法跳出两层循环，借用该标志跳出循环。
    // dfs找第一个岛屿，发现一个一后就进行深度优先搜索。
    for (int i = 0; i < m; ++i) {
      if (flipped) break;
      for (int j = 0; j < n; ++j) {
        if (1 == A[i][j]) {
          dfs(A, points, i, j);
          flipped = true;
          break;
        }
      }
    }

    // 广度优先找第二个岛屿，一找到马上返回。
    int x, y;
    int level = 0;
    while (!points.empty()) {
      ++level;
      int n_points = points.size();
      while (n_points--) {
        auto r = points.front().first;
        auto c = points.front().second;
        points.pop();
        for (int d = 0; d < 4; ++d) {
          x = r + direction[d];
          y = c + direction[d + 1];
          if (x >= 0 && y >= 0 && x < m && y < n) {
            if (2 == A[x][y]) {
              continue;
            }
            if (1 == A[x][y]) {
              return level;
            }
            points.push({x, y});
            A[x][y] = 2;
          }
        }
      }
    }
    return level;
  }

  // 辅助函数，深度优先搜索，用于搜索第一个岛屿，并把找到的岛屿值设为2。
  void dfs(vector<vector<int>>& A, queue<pair<int, int>>& points, int x,
           int y) {
    if (x < 0 || x >= A.size() || y < 0 || y >= A[0].size() || 2 == A[x][y]) {
      return;
    }

    if (0 == A[x][y]) {
      points.push({x, y});
      return;
    }

    A[x][y] = 2;
    for (int d = 0; d < 4; ++d) {
      dfs(A, points, x + direction[d], y + direction[d + 1]);
    }
  }
};
