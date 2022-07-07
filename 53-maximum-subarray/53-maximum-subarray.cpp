/*
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*  Approach -

        Brute force - Calculate the sum of every subarray & compute the maximum sum.

                | _ | _ | _ | _ | _ |  -> suppose this the array
                  0   1   2   3   4
        start -> i, j
                 iterate i through the array & for every i, iterate j through the array
                 and calculate sum += a[j] (so sum = a[0], a[0] + a[1], a[0] + a[1] + a[2]... and so on)

        Optimal - Kadane's algorithm
                1) Logic of the algorithm is the keep calculating the sum of the subarray which yeilds us a positive sum

                2) If a sum is positive even tho its subarray has -ve numbers
                   we keep calculating and comparing it with maxSum

                3) if the sum is negative. we change it to 0

                4) This way we will definitely go through the required subarray & set the maxSum which wont be affected when the sum decreases.

                5) This algorithm's main task is finding the starting point of the subarray because after that
                   we will definitely calculate maximum sum once even if we also iterate through extra elements later.

                6) Because this algorithm is focused only on finding positive sum. 
                   It doesn't work on array all negative arrays.
                
                7) If the array contains all non-positive numbers, then the solution is the largest negative number 
                   (or the empty subarray, if it is permitted)
*/

// Kadane's algorithm -> demands atleast 1 positive element in the array.

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        int maxSum = nums[0];
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};