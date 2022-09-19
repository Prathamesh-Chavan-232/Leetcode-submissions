class Solution
{
    public:
        vector<vector < string>> findDuplicate(vector<string> &paths)
        {
            unordered_map<string, vector < string>> p;

            for (int i = 0; i < paths.size(); i++)
            {
                string s = paths[i];
                int k = 0;
                string start;
                while (!isspace(s[k]) && k < s.size())
                {
                    start += s[k];
                    k++;
                }
                if (k == s.size())
                    continue;

                k++;
                string t;
                string id;
                string emp;
                while (k < s.size())
                {
                    if (isspace(s[k]))
                    {
                        string f = start + '/' + t;
                        f.erase(f.begin() + f.size() - id.size(), f.end());
                        p[id].push_back(f);

                        id = emp;
                        t = emp;
                        k++;

                        continue;
                    }

                    t += s[k];
                    if (s[k] == '(' || id.size() > 0)
                        id += s[k];
                    k++;
                }

                if (id.size() > 0)
                {
                    string f = start + '/' + t;
                    f.erase(f.begin() + f.size() - id.size(), f.end());
                    p[id].push_back(f);
                }
            }

            vector<vector < string>> v;
            int l = 0;
            for (auto i: p)
            {
                if (i.second.size() > 1)
                    v.push_back(i.second);
            }

            return v;
        }
};