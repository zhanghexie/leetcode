# include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int num = 0;
        // 把数组看成一张无向图，visited记录访问过的节点。
        vector<bool> visited(M.size(), false);
        for(int i = 0; i < M.size(); ++i){
            if(!visited[i]){
                dfs(M, i, visited);
                ++num;
            }
        }
        return num;
    }
    
    void dfs(vector<vector<int>>& M, int n, vector<bool> &visited){
        visited[n] = true;
        for(int i = 0; i < visited.size(); ++i){
            if(!visited[i] && 1 == M[i][n]){
                dfs(M, i, visited);
            }
        }
    }
};

