class Solution {
public:
    map<int, int> stonePositions;
    map<pair<int, int>, bool> dp;
    bool canJump(vector<int>& stones, int pos, int k) {
        int lastPos = stones[stones.size() - 1];
        if (pos == lastPos)
            return true;
        if (k <= 0 || pos > lastPos)
            return false;
        if (dp.find({pos, k}) != dp.end()) {
            return dp[{pos, k}];
        }
        if (stonePositions[pos] == 1)
            return dp[{pos, k}] = canJump(stones, pos + k - 1, k - 1) ||
                                  canJump(stones, pos + k, k) ||
                                  canJump(stones, pos + k + 1, k + 1);

        return dp[{pos, k}] = false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false; 
        for(auto stone : stones) {
            stonePositions[stone] = 1;
        }
        return canJump(stones, 1, 1);
    }
};

/*

0 -> 1 :- max 2 units -> 3 :- 1,2,3 -> 6 :- 2,3,4 -> 8 :- 1,2,3 -> stuck
0 -> 1 :- 0,1,2 -> 3 :- 1,2,3 -> 5 :- 1,2,3 -> 8 :- 2,3,4 -> 12 -> 3,4,5 -> 17
-> pass

for each jump we have check if we can make it, recursively

*/