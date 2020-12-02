# include<vector>
# include <stack>
using namespace std;

// 递归形式的写法
class Solution1 {
public:
    vector<int> direction{-1,0,1,0,-1}; // 相邻两个表示一个方向。
    
    // 主函数
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(1 == grid[i][j]){
                    max_area = max(max_area, dfs(grid,i,j));
                }
            }
        }
        return max_area;
    }
    
    // 深度优先搜索
    int dfs(vector<vector<int>>& grid,int x, int y){
        if(0 == grid[x][y]) return 0;
        grid[x][y] = 0; //置为0之后不再搜索。
        int i, j, area = 1;
        for(int d = 0; d < 4; d++){
            i = x + direction[d], j = y + direction[d+1];
            if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()){
                area += dfs(grid, i, j);
            }
        }
        return area;
    }

};

class Solution2 {
public:
    vector<int> direction{-1,0,1,0,-1};
    
    // 主函数
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int local_area, max_area = 0, x, y;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(1 == grid[i][j]){
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int,int>> island;
                    island.push({i,j});
                    while(!island.empty()){
                        auto r = island.top().first;
                        auto c = island.top().second;
                        island.pop();
                        for(int d = 0; d < 4; d++){
                            x = r + direction[d] , y = c + direction[d+1];
                            if(x >= 0 && x < m && y >= 0 && y < n && 1 == grid[x][y]){
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x,y});
                            }
                        }
                    }
                    max_area = max(max_area, local_area);
                }
                
            }
        }
        return max_area;
    }
};
