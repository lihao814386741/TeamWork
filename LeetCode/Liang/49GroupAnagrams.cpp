/**
 * Are there any O(n * averageLen) method?
 **/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        // Here must be map
        map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); ++i) {
            string tmpStr = strs.at(i);
            sort(tmpStr.begin(), tmpStr.end());
            if (hash.find(tmpStr) != hash.end()) {
                vector<string> &vtr = hash[tmpStr];
                vtr.push_back(strs.at(i));
            } else {
                hash[tmpStr] = {strs.at(i)};
            }
        }
        
        vector<vector<string>> result;
        for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
            result.push_back(itr->second);
        }
        return result;
    }
};
