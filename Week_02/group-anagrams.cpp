class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;

        for (string& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            m[s].push_back(str);
        }

        for (auto item: m) {
            result.push_back(item.second);
        }

        return result;
    }
};
