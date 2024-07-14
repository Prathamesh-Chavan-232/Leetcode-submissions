const int N = 1e5 + 10, M = N;
int dp[N];
class Solution {
public:
    int getMinimumCoinsForAmount(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];

        int ans = INT_MAX;
        for (auto coin : coins) {
            if (amount - coin >= 0)
                ans = min(ans + 0LL,
                          getMinimumCoinsForAmount(coins, amount - coin) + 1LL);
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int ans = getMinimumCoinsForAmount(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};