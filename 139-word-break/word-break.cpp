class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        
        map<string, int> mpp;
        
        for (auto it : wordDict) {
            mpp[it]++;
        }
        
        dp[n] = true;
        
        for(int index = n-1; index >= 0; index--){
            
            for(int i = index; i < s.size(); i++){
                string sub = s.substr(index, i - index + 1);
                if(mpp.find(sub) != mpp.end() && dp[i + 1]){
                    dp[index] = true;
                }
            }
            
        }

        return dp[0];
    }
};