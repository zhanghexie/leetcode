# include <iostream>
# include <vector>
using namespace std;

// 采用逆向思维，深度优先搜索出可以流回去的点。
class Solution {
public:
    // 每两个相邻值代表一个方向
    vector<int> direction = {-1,0,1,0,-1};
    // 主函数
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if(matrix.empty() || matrix[0].empty()) return {};
        
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<bool>> arrive_a(m, vector<bool>(n,false));
        vector<vector<bool>> arrive_p(m, vector<bool>(n,false));
        vector<vector<int>> res;

        // 遍历左右竖边
        for(int i = 0; i < m; ++i){
            dfs(matrix, i, 0, arrive_p);   
            dfs(matrix, i, n-1, arrive_a);         
        }

        // 遍历上下横边
        for(int i = 0; i < n; ++i){
            dfs(matrix, 0, i, arrive_p);   
            dfs(matrix, m-1, i, arrive_a); 
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(arrive_a[i][j] && arrive_p[i][j]) res.push_back(vector<int>{i,j});
            }
        }

        return res;
    }

    // 辅助函数将可到达的区域置为真。
    void dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& arrive){
        if(arrive[x][y]) return;
        arrive[x][y] = true;
        int i,j;
        for(int d = 0; d < 4; ++d){
            i = x + direction[d];
            j = y + direction[d+1];
            if(i >= 0 && i < matrix.size() && j >=0 && j < matrix[0].size() && matrix[i][j] >= matrix[x][y]){
                dfs(matrix, i, j, arrive);
            }
        }
    }

};
