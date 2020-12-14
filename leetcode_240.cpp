#include <vector>
using namespace std;

// 解题思路
//  先放到左上角
//  一次砍掉一行或一列

// 代码实现

class Solution1 {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    bool ans = false;
    int m = matrix.size();
    int i = 0, j = matrix[0].size() - 1;

    while (i < m && j >= 0) {
      if (target == matrix[i][j]) {
        return true;
        // 目标值大就砍掉上边一整行。
      } else if (target > matrix[i][j]) {
        ++i;
        // 目标值小就砍掉右边一整列。
      } else {
        --j;
      }
    }
    return ans;
  }
};