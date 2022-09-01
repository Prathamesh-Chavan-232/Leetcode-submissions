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
typedef vector<int> vi;
typedef vector<ll> vl;

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
            num = num *10 + (s[i] - '0');
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
template < typename...Args >
    void logger(string varname, Args && ...values)	// logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// debugger for STL vector / set (of any type)
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
            it != --c.end() ? cerr << *it << ", " : cerr << *it;
        }
        cerr << "}";
    }
/**
 *@brief - Return the leftmost pivot index. If no such index exists, return -1.

 *        [1,7,3  6  5,6]
 *                p
 *     Gradually calculate left-side sum. And check if its equal to right-side sum
 */
// classes &functions
class Solution
{
    public:
        int findMiddleIndex(vector<int> &nums)
        {
            int res = -1;
            int sum = 0, n = nums.size();
            for (int i = 0; i < n; ++i)
            {
                sum += nums[i];
            }
            debug(sum);
            int lSum = 0, rSum = sum;
            for (int i = 0; i < n; i++)
            {

                rSum = rSum - nums[i]; // sum of strictly the right side	
                
                if (lSum == rSum)	// break when they're equal
                {
                    res = i;
                    break;
                }
                
                // sum of strictly left side will keep increasing             
                lSum += nums[i]; 	
            }
            return res;
        }
};