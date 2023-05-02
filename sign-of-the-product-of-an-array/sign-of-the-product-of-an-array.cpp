class Solution {
public:
int arraySign(vector<int>& nums) {
        int n = nums.size();
        int pr = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                pr = 0;
                break;
            }
            else if(nums[i] < 1) {
                pr = pr * -1;
            }
        }
        return pr;
    }
};