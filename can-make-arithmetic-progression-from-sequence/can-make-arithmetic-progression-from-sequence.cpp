class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        int length = arr.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int num : arr) {
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
        }

        double diff = static_cast<double>(max_val - min_val) / (length - 1);

        for (int i = 0; i < length; i++) {
            double expected = min_val + i * diff;
            bool found = false;
            for (int num : arr) {
                if (std::abs(num - expected) < 1e-9) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }

        return true;
    }
};