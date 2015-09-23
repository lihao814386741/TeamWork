static string phoneNum[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        
        string path;
        vector<string> result;
        DFSHelper(digits, 0, path, result);
        return result;
    }
private:
    void DFSHelper(string &digits, int level, string &path, vector<string> &result) {
        if (level == digits.size()) {
            result.push_back(path);
            return;
        }
        
        string tmpStr = phoneNum[digits[level] - '0'];
        for (int i = 0; i < tmpStr.size(); ++i) {
            path += tmpStr[i];
            DFSHelper(digits, level + 1, path, result);
            path.pop_back();
        }
    }
};
