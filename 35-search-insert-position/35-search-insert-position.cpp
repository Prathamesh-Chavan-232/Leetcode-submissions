class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid, res = -1, low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                res = mid;
                break;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if(res == -1)
        {
            res = high + 1;
        }
        return res;
    }
};