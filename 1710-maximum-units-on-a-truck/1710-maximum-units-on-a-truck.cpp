#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pq_max priority_queue<int>                            // max heap
#define pq_min priority_queue<int, vector<int>, greater<int>> // min heap
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
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*  Approach -

    Approach 1: (Brute Force) O(NlogN)
        Sorting the List -
            The given boxTypes will be sorted in descending order depending on the units,
            and then we simply loop through the boxTypes and take boxes equal to truckSize.


    Approach 1: (Optimal) O(N)
        Counting/Bucket sort -
            In this approach, we know that the number of units will not exceed 1000,
            so we create an array to store all the boxes with the given units.

            Eg. boxes with 1 unit will be stored at index 1 in the array
            To iterate through the boxTypes and add the boxes in the given units placed in the array. After that loop through 1000 to 0 and pick up the boxes till the truck is full.

            We are looping through the array from the highest unit boxes to the lowest ones.
*/

// Optimal
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = 1000, maxUnits = 0;
        vi bucket(1001, 0);
        for (auto &box : boxTypes)
        {
            bucket[box[1]] += box[0];
        }
        Fo(i, n, 0)
        {
            if (truckSize <= 0)
                break;

            if (bucket[i] == 0)
                continue;

            int boxes = bucket[i], units = i;
            debug(boxes, units);
            maxUnits += min(boxes, truckSize) * units;
            truckSize -= boxes;
        }
        return maxUnits;
    }
};
// Brute force
class Solution2
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int res = 0;
        sort(all(boxTypes), [](auto a, auto b)
             { return a[1] > b[1]; });
        for (auto &box : boxTypes)
        {
            if (truckSize <= 0)
                break;
            res += min(truckSize, box[0]) * box[1];
            truckSize -= box[0];
        }
        return res;
    }
};