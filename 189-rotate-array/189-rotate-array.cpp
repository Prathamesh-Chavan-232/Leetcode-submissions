#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)

// Shortenting stl function calls
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef priority_queue<int> pqb;
typedef priority_queue<int, vector<int>, greater<int>> pqs;

// Container input tools
void inVec(vector<int> &v)
{
    string s;
    getline(cin, s);
    int num = 0, sign = 1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[' || s[i] == ']')
            continue;
        if (s[i] == '-')
            sign = -1;
        else if (s[i] == ',' || s[i] == ' ')
            v.push_back(num), num = 0;
        else
        {
            num = num * 10 + (s[i] - '0');
            num *= sign;
            sign = 1;
        }
    }
    v.push_back(num);
}

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

// debugger for STL vector / set (of any type)
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
        it != --c.end() ? cerr << *it << ", " : cerr << *it;
    }
    cerr << "}";
}

// Data structures
struct BinTree
{
    int val;
    BinTree *left;
    BinTree *right;
    BinTree() {}
    BinTree(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Function declarations
BinTree *createTree(vector<int> &nodes);

/**
 * @brief
 **APPROACH 1 :
 If k >= n do k = k % n
 *  [1,2,3,4,5], k = 9
 *  first 5 rotations will bring the array back to original
 *  Therefore actual rotations - k % n
 *  ans = [2,3,4,5,1]

 *  nums = [1,2,3,4,5,6,7], k = 3
 *  1st rotation - [7,1,2,3,4,5,6]
 *  2nd rotation - [6,7,1,2,3,4,5]
 *  3rd rotation - [5,6,7,1,2,3,4]
 *
 *  pick the last k elements [n - k, ... , n - 1]  => [5,6,7]
 *  merge the picked up elements with the remaining array

 **APPROACH 2 : Reversal of array

 *   nums = [1,2,3,4,5,6,7], k = 3
 *   Reverse the whole array.                =>  [7,6,5,4,3,2,1]
 *   Then reverse the first k elements.      =>  [5,6,7,4,3,2,1]
 *   Finally reverse the remaining elements. =>  [5,6,7,1,2,3,4]
 */
// classes & functions
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
        {
            k = k % n;
        }
        if (k == 0)
            return;
        debug(k, n);
        int r = n - k;
        int l = 0;
        vi res;
        for (int i = r; i < n; ++i)
        {
            res.pb(nums[i]);
        }
        for (int i = l; i < r; ++i)
        {
            res.pb(nums[i]);
        }
        debcon(res);
        nums = res;
    }
};
class Solution2
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};