// 10.正则表达式匹配
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // dp[i][j]代表s前i位与p的前j位是否匹配。
        // 碰到普通字符：之前匹配且现在相等。
        // 碰道点：之前匹配。
        // 碰到*：
        //      *表示零个前一个字符-> 字符串往前倒两个匹配
        //      *表示一个或多个前一个字符-> 字符串前一位与表达式前一位可匹配（等或点），而且字符串往前倒一位匹配
        // 可以看到最多往前倒了位（但倒两个时*前必然有一个数），我们要确保倒一位不越界，所以要手动初始化一行一列。
        
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        // 初始化第零列
        dp[0][0] = true; //空与空匹配，其余p为空，s不为空都不匹配。

        // 初始化第零行
        for(int j=1; j<n; ++j){
            // 其实就是找类似这种情况：s=“”,p=“a*b*”。
            dp[0][j+1] = p[j]=='*' && dp[0][j-1];    
        }         

        for(int i = 0; i< m; ++i){
            for(int j = 0; j < n; ++j){
                if(p[j] == '*'){
                    dp[i+1][j+1] = dp[i+1][j-1] || ((s[i] == p[j-1] || p[j-1] == '.')&& dp[i][j+1]);
                }else{
                    dp[i+1][j+1] = dp[i][j] && (s[i] == p[j] || p[j] == '.');
                }
            }
        }
        return(dp[m][n]);
    }
};
