#define all(x) x.begin(), x.end()
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(all(s));
        sort(all(t));
        return s == t;
    }
};