class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int N = group.size();
        int MOD = 1e9 + 7;
        
        // Initialize the dp array
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(n+1, vector<int>(minProfit+1)));
        dp[0][0][0] = 1;
        
        // Fill the dp array using the recurrence relation
        for (int i = 1; i <= N; i++) {
            int g = group[i-1];
            int p = profit[i-1];
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    dp[i][j][k] = (dp[i-1][j][k] + (j >= g ? dp[i-1][j-g][max(0, k-p)] : 0)) % MOD;
                }
            }
        }
        
        // Compute the final answer by summing up the values in the dp array
        int ans = 0;
        for (int j = 0; j <= n; j++) {
            ans = (ans + dp[N][j][minProfit]) % MOD;
        }
        
        return ans;
    }
};