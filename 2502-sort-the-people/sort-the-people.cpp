class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> idx(heights.size());

        for (int i = 0; i < heights.size(); i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(),
             [&](int i, int j) { return heights[i] > heights[j]; });

        vector<string> sortedPeople(names.size());
        for (int i = 0; i < names.size(); i++) {
            sortedPeople[i] = names[idx[i]];
        }

        return sortedPeople;
    }
};