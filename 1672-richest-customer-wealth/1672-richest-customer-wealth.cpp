#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long


// Shortenting stl function calls
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

// Typdefs for containers

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vi> vvi;


/**
 * @brief-
 *
 */

// classes & functions
class Solution
{
public:
    int maximumWealth(vvi &accounts)
    {
        int res = 0;
        for (vi vec : accounts)
        {
            int mx = 0;
            for (int i = 0; i < vec.size(); ++i)
            {
                mx += vec[i];
            }
            res = max(mx, res);
        }
        return res;
    }
};