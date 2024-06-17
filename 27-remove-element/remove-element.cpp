class Solution {
public:
    void deleteFromArray(vector<int>& nums, int index) {
        for (int i = index; i < nums.size() - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums[nums.size() - 1] = 0;
    }

    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                deleteFromArray(nums, i);
                size--;
                i--;
            }
        }
        return size;
    }
};

