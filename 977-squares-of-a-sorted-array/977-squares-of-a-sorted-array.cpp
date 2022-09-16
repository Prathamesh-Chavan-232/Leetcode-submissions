#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
// Shortenting stl function calls
#define pb push_back
#define all(x) x.begin(), x.end()
// Typdefs for containers
typedef vector<int> vi;
typedef vector<ll> vl;

/**
 * @brief- Given a sorted array with both negative & positive numbers,
 *         Return a array with a
 *
 */
// classes & functions
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &arr)
    {
        vi res;
        int n = arr.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i)
        {
            int left = abs(arr[l]);
            int right = abs(arr[r]);
            if (left < right)
            {
                res.pb(right * right);
                r--;
            }
            else
            {
                res.pb(left * left);
                l++;
            }
        }
        reverse(all(res));
        return res;
    }

    // Sqaure each element & sort the array again.
    vector<int> sortedSquares2(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] *= nums[i];
        }
        sort(all(nums));
        return nums;
    }
};
