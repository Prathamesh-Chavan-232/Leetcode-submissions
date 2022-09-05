
// classes & functions
class Solution
{
public:
    int lb(vector<int> &nums, int target)
    {
        int res = -1;
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        if (nums[hi] == target)
        {
            res = hi;
        }
        if (nums[lo] == target)
        {
            res = lo;
        }
        return res;
    }
    int ub(vector<int> &nums, int target)
    {
        int res = -1;
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (nums[lo] == target)
        {
            res = lo;
        }
        if (nums[hi] == target)
        {
            res = hi;
        }
        return res;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        if(nums.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int lwb = lb(nums, target);
        int upb = ub(nums, target);
        ans.push_back(lwb);
        ans.push_back(upb);
        return ans;
    }
};