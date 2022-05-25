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

#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif

#ifndef ONLINE_JUDGE
#define debmap(x)        \
    cerr << #x << " = "; \
    _printmap(x);        \
    cerr << "\n";
#else
#define debmap(x)
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

template <typename T>
void _print(T const &c) // print any type of vector / set
{
    cerr << "{ ";
    foreach (it, c)
        cerr << *it << ", ";
    cerr << "}";
}

template <typename T, typename U>
void _printmap(map<T, U> m)
{
    cerr << "{ ";
    formap(m)
    {
        cerr << "{" << key << "," << value << "} ";
    }
    cerr << "}";
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
    Link -
    Problem -
    Difficulty -
    contest -
    Status -
    Date -
*/
/*  Approach -

*/

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int res = 0;
        sort(all(arr2));
        fo(i, arr1.size())
        {
            bool flag = true;
            int ai = arr1[i];
            int l = 0, r = arr2.size() - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2; 
                int aj = arr2[m];
                if (abs(ai - aj) <= d)
                {
                    flag = false;
                    break;
                }
                else if (aj > ai)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            if (flag)
            {
                res++;
            }
        }
        return res;
    }
};

