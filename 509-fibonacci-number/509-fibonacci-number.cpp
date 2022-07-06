// dp, o(1) space
class Solution
{
    public:
        int fib(int n)
        {
            if (n <= 1)
            {
                return n;
            }

           	// initialize base case variables
            int a = 0, b = 1;
            int sum = 0;

            while (n > 1)
            {
               	// calculate next value as the sum of previous two values
                sum = a + b;

               	// switch all values to the next value in the series
                a = b;
                b = sum;

               	// decrement counter
                n--;
            }

            return sum;
        }
};

// Dp, O(n) -> for pre-computation if multiple testcases
const int N = 30;
class Solution2
{
    public:
        int fib(int n)
        {
            if (n <= 0) return 0;
            if (n == 1) return 1;
            if (n == 2) return 2;
            vector<int> hsh(N);
            hsh[1] = hsh[2] = 1;
            for (int i = 2; i < N; ++i)
            {
                hsh[i] = hsh[i - 2] + hsh[i - 1];
            }
            return hsh[n];
        }
};

// Naive recursive solution
class Solution3
{
    public:
        int fib(int n)
        {
            if (n == 0) return 0;
            if (n == 1) return 1;

            return fib(n - 1) + fib(n - 2);
        }
};