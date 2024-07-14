const int N = 2515;
int dp[N];

class Solution {
public:
    int lis(vector<int>& nums, int last) {
        if (dp[last] != -1)
            return dp[last];

        int res = 1;
        for (int i = 0; i < last; i++) {
            if (nums[last] > nums[i])
                res = max(res, lis(nums, i) + 1);
        }
        return dp[last] = res;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, lis(nums, i));
        }
        return ans;
    }
};
