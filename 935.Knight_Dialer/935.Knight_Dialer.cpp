class Solution {
public:
    int dfs(int n, int v, vector<vector<int>> &moves, vector<vector<int>> &dp) {

        if (n == 0) {
            return 1;
        }
        
        if (dp[n][v] > 0) {
            return dp[n][v];
        }
        
        int count = 0;
        
        for (int i = 0; i < moves[v].size(); ++i) {
            int to = moves[v][i];
            count = (count + dfs(n-1, to, moves, dp)) % 1000000007;
        }
        
        dp[n][v] = count;
        
        return dp[n][v];
    }
    
    int knightDialer(int N) {
        vector<vector<int>> moves = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 0, 7},
            {2, 6},
            {1, 3},
            {4, 2}
        };
        
        vector<vector<int>> dp(N+1, vector<int>(10, -1));
        
        int ans = 0;
        
        for (int i = 0; i <= 9; ++i) {
            ans = (ans + dfs(N-1, i, moves, dp)) % 1000000007;
        }
        
        return ans;
    }
};
