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

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


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
           	// Write your code here.

            int temp;
            vvi pascal(n);
            pascal[0].pb(1);

            if (n > 1)
            {
                pascal[1].pb(1);
                pascal[1].pb(1);
            }
            for (int i = 2; i < n; ++i)
            {
                for (int j = 0; j <= pascal[i - 1].size(); ++j)
                {
                    if (j - 1 < 0)
                    {
                        temp = 0 + pascal[i - 1][j];
                        pascal[i].pb(temp);
                    }
                    else if (j == pascal[i - 1].size())
                    {
                        temp = 0 + pascal[i - 1][j - 1];
                        pascal[i].pb(temp);
                    }
                    else
                    {
                        temp = pascal[i - 1][j - 1] + pascal[i - 1][j];
                        pascal[i].pb(temp);
                    }
                }
            }
            return pascal;
        }
};