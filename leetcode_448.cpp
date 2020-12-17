// 448 找到所有数组中消失的数字
#include<iostream>
#include<vector>
using namespace std;

// 为了节省空间可以将已出现的数值（取绝对值）减1作为索引，将输出向量索引处的值设为负。
// 因为遍历到的值有可能已经被置为负数负，所以要加绝对值。

class Solution {
// 注意观察题目 1 <= a[i] <= n
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> ans;
      // 遍历所有值，以值为索引将其
      for(int num : nums) {
        int pos = abs(num) - 1;
        // 精华
        if(nums[pos] > 0) {
          nums[pos] = -nums[pos];
        } 
      }
      // 找出还为正值的索引
      for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] > 0) {
          ans.push_back(i+1);
        }
      }
      return ans;
    }
};