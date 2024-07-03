#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)

// Shortenting stl function calls
#define pb push_back
#define all(x) x.begin(), x.end()

// Typdefs for containers
typedef vector<int> vi;
typedef vector<ll> vl;

/**  @brief -
        1) Brute force
            For each index in the array, linearly traverse through the indices
   after it and check if sum of 2 elements equals target

        2) Better - Two pointer approach
            Sort the array and take 2 pointers start and end and check if
   nums[start] + nums[end] == target

            if the sum is smaller move start forward (we need a bigger sum)
            if the sum is greater move end backward (we need a smaller sum)

        3) Optimal - hash map
            At start, take an empty hash map
            Iterate through the array and for each iteration,
            1) Add arr[i] to the map
            2) Check if target - arr[i] exists in the hash map

        Since a pair always exists when we add arr[i], when we iterate through
   its pair it will find arr it in the map as target - arr[i]

*/

// classes & functions
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> res;
        int n = arr.size();
        unordered_map<int, int> hsh;
        for (int i = 0; i < n; ++i) {
            int x = target - arr[i];      // check if its pair exists in the map
            if (hsh.find(x) != hsh.end()) // if it does, store them.
            {
                res.pb(i);
                res.pb(hsh[x]);
                break;
                // push the indices of the elements
            }
            hsh[arr[i]] = i; // add array element in the map
        }
        return res;
    }
};