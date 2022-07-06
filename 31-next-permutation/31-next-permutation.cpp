#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define formap(m) for (auto [key, value] : m)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// STL vector / set (of any type) debugger
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c)
{
    cerr << "{ ";
    foreach (it, c)
    {
        cerr << *it << ", ";
    }
    cerr << "}";
}

// Function definitions
void Add_edge(int v1, int v2);
void dfs(int vertex);

// constants
const int mod = 1'000'000'007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

vpii graph[N]; // For Adjacency List
bool vis[N];

/*
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*  Approach -

        Logic - Minimize the change in the number after swapping.
        Eg - [1, 3, 5, 4, 7, 6, 2]

                        7
                            6
                5                       =>    After algorithm  - [1,3,5,6,2,4,7]
            3       4
        1                        2
        Every permuation has - a Highest Peak, left increasing sequence, right increasing sequence.

        1) find i such that arr[i] < arr[i+1] (from the back)
        2) Iterate again to find j such arr[j] > arr[i] (from the back)
        3) Swap arr[j] with arr[i]
        4) Reverse the array from index = i + 1 to the end

        Code -
            1) Find i, if i does not exist i.e descending order case -> directly reverse.
            2) Else Run 2nd loop from last element until i
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i, j;
        for (i = n - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                break;
            }
        }
        if (i < 0)
        {
            reverse(all(nums));
        }
        else
        {

            for (j = n - 1; j >= i; --j)
            {
                if (nums[j] > nums[i])
                {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
        debcon(nums);
    }
};
class Solution2
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int n = nums.size();
            next_permutation(nums.begin(), nums.end());
        }
};