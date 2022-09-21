/* Bottom up DP approach */
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int i, j, ret = 0;
        
        for (i=nums1.size()-1; i >= 0; i--) {
            for (j=nums2.size()-1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                    if (dp[i][j] > ret)
                        ret = dp[i][j];
                }
            }
        }
        return ret;
    }
};