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
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> ml;
typedef set<ll> sl;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_set<ll> usl;

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

// Varadiac I/O
template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void write(T &&...args)
{
    ((cout << args << " "), ...);
    cout << "\n";
}

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;
vi graph[N]; // For Adjacency List

/*
    Link - https://leetcode.com/problems/subsets/
    Problem - Generate all possible subsets of a given set
    Difficulty - Medium
    Topic - Recursion & backtracking
    Status - Solved
    Date - 13/5/22
*/
/*  Approach -
        There are 2 choices for each element either we it is present in the sub-set, 
        or it isnt present.

        Back tracking step -
            Therefore after adding an element to the set, we make a recursive call for the modified set 
            Then, we pop that element and make a recursive call again (This is the element not added case)

        E.g. -> S = [1,2] subsets = [[],[1],[2],[1,2]];
        
         []   ------> Starting from null set
       /    \
    [1]      [] --------> Add/ Dont add - 1
  /    \    /  \
[1,2]  [1] [2]  [] --------> Add/ Dont add - 2

After traversing all the elements we will find all possible subsets
*/

class Solution
{
    vvi res;

public:
    void generate(vi &nums, vi &subset, int i)
    {
        if (i == nums.size())
        {
            res.pb(subset);
            return;
        }
        subset.pb(nums[i]);
        generate(nums, subset, i + 1);
        subset.pop_back();
        generate(nums, subset, i + 1);
    }
    vector<vector<int>> subsets(vi &nums)
    {
        vi subset;
        generate(nums, subset, 0);
        return res;
    }
};
int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    Solution s;
    int n;
    read(n);
    vi nums(n);
    fo(i, n) read(nums[i]);
    vvi res = s.subsets(nums); // store return value
    cout << "{ ";
    for (vi vec : res)
    {
        cout << "[ ";
        for (int val : vec)
        {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << " }";

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}
