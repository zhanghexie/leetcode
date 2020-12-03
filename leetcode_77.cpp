// 77 组合

# include <iostream>
# include <vector>
using namespace std;

// 回溯算法
class Solution1 {
public:
    //主函数
    vector<vector<int>> combine(int n, int k) {
        if(n < k) return{};
        vector<vector<int>> res;
        vector<int> comb(k,0);
        // 记录该在第几位放数了
        int count = 0;
        bt(res, comb, n, k, count, 1);
        return res;
    }

    // 辅助函数 
    // res，comb，cout，都得是引用类型。
    void bt(vector<vector<int>> &res, vector<int> &comb, int n, int k, int &count, int pos){
        if(k == count){
            res.push_back(comb);
            return;
        }
        for(int i = pos; i < n+1; ++i){
            comb[count++] = i;
            // 当前应放置数的位置pos=i+1。
            bt(res, comb, n, k, count, i+1);
            --count;
        }
    }
};
