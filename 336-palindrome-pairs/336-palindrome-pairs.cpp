class Solution
{
    public:
        std::vector<std::vector < int>> palindromePairs(std::vector<std::string > &words)
        {
            const int n = words.size();
            std::vector<std::vector < int>> result;
            std::unordered_map<std::string, int> map_;
            std::set<int> set_;
            for (int i = 0; i < n; i++)
            {
                map_[words[i]] = i;
                set_.insert(words[i].size());
            }
            for (int i = 0; i < n; i++)
            {
                std::string temp = words[i];
                int len = temp.size();
                std::reverse(temp.begin(), temp.end());
                if (map_.count(temp) && map_[temp] != i)
                {
                    result.push_back({ i,
                        map_[temp] });
                }
                auto a = set_.find(len);
                for (auto it = set_.begin(); it != a; it++)
                {
                    int d = *it;
                    if (isValid(temp, 0, len - d - 1) && map_.count(temp.substr(len - d)))
                    {
                        result.push_back({ i,
                            map_[temp.substr(len - d)] });
                    }
                    if (isValid(temp, d, len - 1) && map_.count(temp.substr(0, d)))
                    {
                        result.push_back({ map_[temp.substr(0, d)],
                            i });
                    }
                }
            }
            return result;
        }
    bool isValid(std::string temp, int left, int right)
    {
        while (left < right)
        {
            if (temp[left++] != temp[right--]) return false;
        }
        return true;
    }
};