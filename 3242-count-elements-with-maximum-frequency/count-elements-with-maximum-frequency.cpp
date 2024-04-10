#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args> void logger(string varname, Args &&...values) {
  cerr << varname << " = ";
  string delim = "";
  (..., (cerr << delim << values, delim = ", "));
  cerr << "\n";
}

// Vector Debugger
#ifndef ONLINE_JUDGE
#define debvec(x)                                                              \
  cerr << #x << " = ";                                                         \
  _print(x);                                                                   \
  cerr << "\n";
#else
#define debvec(x)
#endif
template <typename T> void _print(T const &c) {
  cerr << "{ ";
  for (auto it = c.begin(); it != c.end(); it++) {
    cerr << *it << ", ";
  }
  cerr << "}";
}

/**
 * @brief-
 *
 *
 */


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        vector<int> freq(101);
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }

        int res = 0;
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] == maxFreq) res += freq[i];
        }
        return res;
    }
};