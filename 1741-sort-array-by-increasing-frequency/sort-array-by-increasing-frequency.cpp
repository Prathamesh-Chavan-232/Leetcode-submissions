class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> fq;
        for (auto itr : mp) {
            fq.push_back({itr.first, itr.second});
        }

        sort(fq.begin(), fq.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {

                return a.first > b.first;
            }
        });

        vector<int> ans;
        for (int i = 0; i < fq.size(); i++) {
            pair<int, int> pr = fq[i];
            while (pr.second--) {
                ans.push_back(pr.first);
            }
        }
        return ans;
    }
};