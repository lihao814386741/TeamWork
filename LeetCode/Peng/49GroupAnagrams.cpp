class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> category;
        for (int i = 0; i < n; i++) {
            string temp = strs.at(i);
            sort(temp.begin(), temp.end());
            category[temp].push_back(strs.at(i));
        }
        unordered_map<string, vector<string>>::iterator iter;
        for (iter = category.begin(); iter != category.end(); iter++) {
            sort(iter->second.begin(), iter->second.end());
            result.push_back(iter->second);
        }
        return result;
    }
};