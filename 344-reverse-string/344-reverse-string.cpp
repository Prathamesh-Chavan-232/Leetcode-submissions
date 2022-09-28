class Solution
{
    public:
        void reverseString(vector<char> &str)
        {
            int n = str.size();
            for (int i = 0; i < n / 2; i++)
                swap(str[i], str[n - i - 1]);
        }
};