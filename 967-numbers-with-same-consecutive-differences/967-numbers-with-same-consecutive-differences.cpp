class Solution
{
    public:
        vector<int> ans;
    void rcheck(int num, int k, int n)
    {
        if (n == 1)
        {
            ans.push_back(num);
            return;
        }
        if (num % 10 - k >= 0) rcheck(num *10 + (num % 10 - k), k, n - 1);
        if (k)
        {
            if (num % 10 + k < 10) rcheck(num *10 + (num % 10 + k), k, n - 1);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        for (int i = 1; i < 10; i++) rcheck(i, k, n);
        return ans;
    }
};