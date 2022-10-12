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


/**
 * @brief
 *
 *  E.g. - Let's take the leetcode contest
 *         ^    ^
 *         i    j
 *
 *    When s[i] is not a white-space, find the
 *    next white-space and move j to it.
 *
 *    reverse substring s[i] -> s[j - 1]
 */
// classes & functions

class Solution
{
public:
    string reverseWords(string s)
    {
        int j = 0, n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != ' ')
            {
                j = i;
                while (j < s.size() && s[j] != ' ')
                {
                    j++;
                }
                reverse(s.begin() + i, s.begin() + j);
                debug(i, j);
                i = j - 1;
            }
            debug(s[i], i);
        }
        return s;
    }
};