// 46.全排列

# include <iostream>
# include <vector>
using namespace std;


// 回溯法，交换，参考图46。
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(nums, 0, res);
        return res;
    }

    void backtracking(vector<int> &nums, int level, vector<vector<int>> &res){
        if(level == nums.size() -1){
            res.push_back(nums);
            return;
        }

        for(int i = level; i < nums.size(); ++i){
            swap(nums[i], nums[level]);
            backtracking(nums, level+1, res);
            swap(nums[i], nums[level]);
        }
    }
};
