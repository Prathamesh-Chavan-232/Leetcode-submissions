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
 *
 */
// classes & functions
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        debug(s, t);
        unordered_map<char, char> mp1, mp2;
        for (int i = 0; i < s.size(); ++i)
        {
            if (mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i])
                return false;
            if (mp2.find(t[i]) != mp2.end() && mp2[t[i]] != s[i])
                return false;

            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};