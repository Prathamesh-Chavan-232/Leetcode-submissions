#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long
#define pb push_back
#define mp make_pair
#define pqb priority_queue < int>
#define pqs priority_queue<int, vector < int>, greater < int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// constants
const int mod = (int) 1e7;
const int N = 3e5,
    M = N;

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " = " << x << "\n";
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debcon(x)\
cout << #x << " = ";\
_print(x);\
cout << "\n";
#else
#define debcon(x)
#endif

// Function definitions
template < typename T>
    void _print(T
        const &c)	// print any STL container
{
    cout << "{";
    tr(it, c) cout << *it << ", ";
    cout << "}";
}

/*
    Link -
    Problem -
    Difficulty -
    contest -
    Status -
    Date -
*/
/*Approach -

*/

class Solution
{
    public:
        vector<vector < int>> generate(int n)
        {
            vvi pascal(n);
            fo(i, n)
            {
                pascal[i].resize(i + 1);
                pascal[i][0] = pascal[i][i] = 1;
                for (int j = 1; j < i; j++)
                {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
            return pascal;
        }
};