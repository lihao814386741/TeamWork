class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string path;
        vector<string> result;
        restoreDFSHelper(s, 4, path, result);
        return result;
    }
    
private:
    void restoreDFSHelper(string s, int segment, string &path, vector<string> &result) {
        if (segment == 0 && s.size() == 0) {
            //path.pop(); // This will have problem with 27:
            result.push_back(path.substr(0, path.size() - 1));
            return;
        }
        
        // If s is too long or too short.
        if (s.size() > segment * 3 || s.size() < segment) {
            return;
        }
        
        for (int i = 1; i <= 3 && i <= s.size(); ++i) {
            if (stoi(s.substr(0, i)) <= 255) {
                path = path + s.substr(0, i) + '.';
                restoreDFSHelper(s.substr(i), segment - 1, path, result);
                path = path.substr(0, path.size() - i - 1);
                if (s[0] == '0') {
                    break;
                }
            }
        }
    }
};
