#include <bits/stdc++.h>
using namespace std;

// Typdefs for containers
typedef vector<int> vi;

// classes & functions
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vi r(26), m(26);
        for (char ch : ransomNote)
            r[ch - 'a']++;

        for (char ch : magazine)
            m[ch - 'a']++;
        for (int i = 0; i < r.size(); ++i)
        {
            if (r[i] > m[i])
                return false;
        }
        return true;
    }
};
