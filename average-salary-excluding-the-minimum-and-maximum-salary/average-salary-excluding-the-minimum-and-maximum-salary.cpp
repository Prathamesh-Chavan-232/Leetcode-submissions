class Solution {
public:
    double average(vector<int>& salary) {
        int n  = salary.size();
        int min = INT_MAX, max = 0, sum = 0;

        for(int i = 0; i < n; i++) {
            if(salary[i] > max) max = salary[i];
            if(salary[i] <= min) min = salary[i];
            sum += salary[i];
        } 

        sum = sum - min - max;
        double avg = (sum * 1.0) / (n - 2);
        return avg; 
    }
};