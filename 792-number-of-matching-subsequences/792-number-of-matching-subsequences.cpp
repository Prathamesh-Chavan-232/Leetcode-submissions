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
        else if (s[i] == ',')
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
const int mod = 1000000007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

vpii graph[N]; // For Adjacency List
bool vis[N];

/*
    Link - https://leetcode.com/problems/number-of-matching-subsequences/
    Problem - July leetcode challenge 2022
    Difficulty - Medium
    topic - hashing & binary search
    Status - solved
    Date - 20/7/2022
*/
/*  Approach -
        
        Brute force -
            To check if a sttring is a subsequence or not all we need to do is check if the all characters in the string
            are also in the original string & in the same order
            This can be done by iterating the string using 2 pointers, (we have to do this for each word)
            we move the pt2 forward if the char of string matches the curr char of original string
            else we move pt1 forward
            if pt1 (ptr of original string), reaches end before pt2 (ptr of string to be checked), it isnt a subsequence
        
        Hashing & Binary search -
            Instead of iterating through the string for each word in words
            We can store the indices at which each character occurs in a map / vec of vec
            Since indicies will always be stored in sorted order
            we can do binary search to check if the character is available in the original string
            
        eg -  a b c d b e
        words = ["a","bb","kk", "acd","ace"]
        a -> 0
        b -> 1 4
        c -> 2
        d -> 3
        e -> 5
        
        each character has its vector, search if the character is available to be stored in a subsequence
        prev = -1
        consider words[0] = "bb" 
        word in words, for i = 0, word[i] = b, vector is {1,4}
        since the the an index greater than prev, b is present in subsequence, so prev = 1
        for i = 1, word[i] = b, vector is {1, 4} & prev = 1
        since index greater than prev is present in the vector, b is also in the subsequence
        if the all characters of the word pass the check then ans++

*/

class Solution
{

public:
    int numMatchingSubseq(string &s, vector<string> &words)
    {

        int ans = 0;
        unordered_map<char, vi> indices;
        for (int i = 0; i < s.size(); i++)
        {
            indices[s[i]].pb(i);
        }
        for (auto &word : words)
        {
            int prev = -1;
            bool found = true;
            for (int i = 0; i < word.size() && found; ++i)
            {
                vi &vec = indices[word[i]];
                auto it = upper_bound(all(vec), prev);
                if (it == vec.end())
                    found = false;
                else
                    prev = *it;
            }
            ans += found;
        }
        return ans;
    }
};
