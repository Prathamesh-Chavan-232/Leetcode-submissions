#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define pb push_back
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