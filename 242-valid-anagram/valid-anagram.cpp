class Solution {
public:
    bool isAnagram(string str1, string str2) {
        if(str1.size() != str2.size()) 
            return false;

       vector<int> freq(26);
       bool res = true;
       for(int i = 0; i < str1.size(); ++i) {
        int index = str1[i] - 'a';
        freq[index]++;

        index = str2[i] - 'a';
        freq[index]--;
       }
       for(int i = 0; i < freq.size(); ++i) {
            if(freq[i] != 0) {
                res = false;
                break;
            }
       }
       return res;
    }
};