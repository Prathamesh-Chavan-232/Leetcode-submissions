#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pq_max priority_queue < int>
#define pq_min priority_queue<int, vector < int>, greater < int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define formap(m) for (auto[key, value]: m)
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
template < typename...Args >
    void logger(string varname, Args && ...values)	// logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// STL vector / set (of any type) debugger
#ifndef ONLINE_JUDGE
#define debcon(x)\
cerr << #x << " = ";\
_print(x);\
cerr << "\n";
#else
#define debcon(x)
#endif
template < typename T>
    void _print(T
        const &c)
    {
        cerr << "{ ";
        foreach(it, c)
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
const int N = 1e5 + 10,
    M = N;
const double PI = 3.1415926535897932384626;

vpii graph[N];	// For Adjacency List
bool vis[N];

/*
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*Approach -

*/

class Solution
{
    public:
        int getMax(vi arr, int x)
        {
            int n = arr.size();
            int max_ = max(arr[0], x - arr[n - 1]);
            for (int i = 0; i < n - 1; ++i)
            {
                int cut = arr[i + 1] - arr[i];
                max_ = max(max_, cut);
            }
            return max_;
        }
    int maxArea(int h, int w, vector<int> &hCuts, vector<int> &vCuts)
    {
        sort(all(hCuts));
        sort(all(vCuts));
        int n = hCuts.size(), m = vCuts.size();
        int maxH = getMax(hCuts,h), maxW = getMax(vCuts,w);
        int maxArea = (1LL *maxH *maxW) % mod;
        return maxArea;
    }
};