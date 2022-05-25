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
    Link - https://leetcode.com/problems/find-smallest-letter-greater-than-target/
    Problem - find smallest letter greater than given target
    Difficulty - easy
    topic - binary search / searching
    Status - solved
    Date - 25 /5/22
*/
/*  Approach -


        c f j
        c f j
        0 1 2

        l = 0
        mid = 1
        r = 2

        l = 0
        r = 1
*/

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int l = 0, r = letters.size() - 1;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            debug(l, mid, r);
            debug(letters[l], letters[mid], letters[r]);
            if (letters[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        char res = '0';
        if (letters[r] > target)
        {
            res = letters[r];
        }
        if (letters[l] > target)
        {
            res = letters[l];
        }
        if (res == '0')
        {
            res = letters[0];
        }
        return res;
    }
};