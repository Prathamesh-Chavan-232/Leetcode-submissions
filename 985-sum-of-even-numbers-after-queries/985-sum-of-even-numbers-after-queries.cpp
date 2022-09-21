class Solution
{
    public:
        vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector< int>> &queries)
        {
            vector<int> result;

            int n = nums.size();
            long int sum = 0;
            for (int i = 0; i < n; i++)
                if (nums[i] % 2 == 0)
                    sum += nums[i];

            for (int i = 0; i < queries.size(); i++)
            {
                int a = queries[i][0];
                int b = queries[i][1];

                int c = nums[b] + a;
                if (nums[b] % 2 == 0)
                {
                    if (c % 2 != 0)
                    {
                        sum -= nums[b];
                        nums[b] = c;
                    }
                    else
                    {
                        sum += a;
                        nums[b] = c;
                    }
                    result.push_back(sum);
                }
                else
                {
                    if (c % 2 == 0)
                        sum += c;
                    nums[b] = c;
                    result.push_back(sum);
                }
            }
            return result;
        }
};