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
    Link - https://leetcode.com/problems/remove-palindromic-subsequences/
    Problem - Remove Palindromic Subsequence
    Difficulty - Easy
    Topic - Strings
    Status - Solved
    Date - 8/6/22

    Note - 'Note that a subsequence does not necessarily need to be contiguous'
*/
/*  Approach -

    If the string is a palindrome, the answer is 1 and

    If the string is not palindrome, the answer is 2, becuase:
        String s only consists of two characters 'a' and 'b',
        This implies, there always exists two different palindromic subsequence in the string, one consisting of all the a's and other consisting of all the b's.
        We just need to identify if there is a need to return 2 as a result or 1(in case of palindrome)

    Also if the string size is zero - the answer is 0
*/

class Solution
{
public:
    int removePalindromeSub(string S)
    {
        if (S == "")
            return 0;
        for (int i = 0, j = S.size() - 1; i < j; i++, j--)
            if (S[i] != S[j])
                return 2;
        return 1;
    }
};