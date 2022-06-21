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
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*  Approach -

        Jump Down - If the height of the next building is less than the height of the current building, we can jump directly

        Jump Up - We can use ladder for any height, so we have to use it at the maximum possible height.

                1) So for every jump up, first we use the bricks & store the number of bricks used at each jump.
                   if we can't reach the building by using bricks, We should use Ladder at some position / current position

                2) we use a ladder at the position where maximum number of bricks were required
                   Hence we get maxium possible bricks back & can use them to jump up further

                3) We store the number of bricks used at each jump in a Max Heap,
                   so that the max. no of bricks used in a jump is always at the top
*/

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int res = 0;
        int n = heights.size();
        pqb maxB; // Max heap
        int i = 0;
        for (; i < n - 1; ++i)
        {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0) // Continue directing if jumping down
                continue;

            bricks -= diff;  // Using bricks to jump up
            maxB.push(diff); // Pushing in max heap

            if (bricks < 0) // Ran out of bricks, checking where ladder should be used
            {
                bricks += maxB.top(); // getting maximum bricks back, by using ladder instead
                maxB.pop();
                ladders--;
            }

            if (ladders < 0)
                break;
        }
        return i;
    }
};