/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low, mid, high, ans = -1;
        low = 0;
        high = n;
        int res;
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            res = guess(mid);
            if(res == 0)
            {
                ans = mid;
                break;
            }
            else if(res == 1) // Number is greater
            {
                low = mid + 1;
            }
            else // Number is smaller
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};