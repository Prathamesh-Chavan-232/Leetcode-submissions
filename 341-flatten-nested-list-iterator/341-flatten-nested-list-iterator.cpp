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

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif


// Function definitions
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// Varadiac I/O
template <typename... T>
void r(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void w(T &&...args)
{
    ((cout << args << " "), ...);
    cout << "\n";
}
// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*
    Link - https://leetcode.com/problems/flatten-nested-list-iterator/
    Problem - Flatten nested iterator (dfs & stack)
    Difficulty - Easy (dfs), Medium (stack) 
    contest - daily leetcode may 2022
    Status - solved + hints (dfs),
    Date - 09/5/22
*/
/*  Approach -
    Ignore the NestedInteger not defined errors (its an ADT) code was accepted on leetcode.

*/

/**
 *  This is the interface that allows for creating nested lists.
 *  You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     Return the nested list that this NestedInteger holds, if it holds a nested list
 *     The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
    int ct = 0;
    vector<int> flattenList;

public:
    void dfs(NestedInteger x) // x -> integer || list
    {
        if (x.isInteger())
        {
            flattenList.pb(x.getInteger());
        }
        else
        {
            for (auto val : x.getList()) // again dfs on each value in the list
            {
                dfs(val);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        fo(i, n)
        {
            dfs(nestedList[i]);
        }
    }

    int next()
    {
        return flattenList[ct++];
    }

    bool hasNext()
    {
        if (ct < flattenList.size())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
