class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int>satwik;
        
        while(i<j)
        {
            if(numbers[i]+numbers[j]>target) j--;
            else if(numbers[i]+numbers[j]<target) i++;
            else
            {
                satwik.push_back(i+1);
                satwik.push_back(j+1);
                break;
            }
        }
        
        return satwik;
    }
};