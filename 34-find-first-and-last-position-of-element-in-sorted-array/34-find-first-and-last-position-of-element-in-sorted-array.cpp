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
    Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    Problem - find the first and last position of repeated element
    Difficulty - medium
    topic - Binary search
    Status - solved
    Date - 25/5/22
*/
/*  Approach -

*/

class Solution
{
public:
    int lb(vector<int> &arr, int target)
    {
        int mid, res = -1, l = 0, r = arr.size() - 1;

        debug(l, r);
        if (arr.size() == 0)
            return res;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
            debug(l, mid, r);
            if (arr[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if (arr[r] == target)
        {
            res = r;
        }
        if (arr[l] == target)
        {
            res = l;
        }
        debug(res);
        return res;
    }
    int ub(vector<int> &arr, int target)
    {
        int mid, res = -1, l = 0, r = arr.size() - 1;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
            if (arr[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        debug(arr[l], arr[r]);
        if (arr[r] > target)
        {
            res = r - 1;
        }
        if (arr[l] > target)
        {
            res = l - 1;
        }
        debug(res);
        if (res == -1)
        {
            res = arr.size() - 1;
        }
        return res;
    }
    vector<int> searchRange(vector<int> &arr, int target)
    {

        vi ans;
        int temp;
        temp = lb(arr, target);
        ans.pb(temp);
        if (temp != -1)
        {
            temp = ub(arr, target);
        }
        ans.pb(temp);
        return ans;
    }
};