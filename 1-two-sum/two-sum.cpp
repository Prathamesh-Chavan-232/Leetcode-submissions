#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vl;


/*
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/* Approach -

*/

class Solution
{
    public:
        vector<int> twoSum(vector<int> &arr, int target)
        {
            vi res, nums;
            int n = arr.size();
            nums = arr;
            sort(all(nums));
            int start = 0, end = n - 1, n1, n2;

            while (start < end)
            {
                if (nums[start] + nums[end] == target)
                {
                    n1 = nums[start];
                    n2 = nums[end];
                    break;
                }
                else if (nums[start] + nums[end] < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                if (n1 == arr[i] || n2 == arr[i])
                    res.pb(i);
            }
            return res;
        }
};