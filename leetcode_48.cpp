// 48 旋转图像
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size() - 1;
    int tmp = 0;
    for (int i = 0; i <= n / 2; ++i) {
      for (int j = i; j < n - i; ++j) {
        // 从起始点开始依次旋转之后的坐标位置。
        // 1 : [i][j];
        // 2 : [j][n-i];
        // 3 : [n-i][n-j];
        // 4 : [n-j][i];

        // 把谁拿出来，就要赶紧把这个位子填上，而填这个位子的值来自与旋转前位置处的值。
        tmp = matrix[i][j];

        matrix[i][j] = matrix[n - j][i];
        matrix[n - j][i] = matrix[n - i][n - j];
        matrix[n - i][n - j] = matrix[j][n - i];
        matrix[j][n - i] = tmp;
      }
    }
  }
};
