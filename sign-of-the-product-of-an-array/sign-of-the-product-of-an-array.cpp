class Solution {
public:
int arraySign(vector<int>& nums) {
        int n = nums.size();
        int negatives = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                return 0;
            }
            else if(nums[i] < 1) {
                negatives++;
            }
        }
        return negatives % 2 == 0 ? 1 : -1;
    }
};