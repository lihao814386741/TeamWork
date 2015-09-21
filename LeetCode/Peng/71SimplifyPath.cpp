/**
 * Use vector (array) or stack to store each words
 **/ 
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if (!n) return "";
        string result = "";
        vector<string> directs;
        for (int i = 0; i < n; i++) {
            while (i < n && path.at(i) == '/') {
                i++;
            }
            int pos = i;
            while (i < n && path.at(i) != '/') {
                i++;
            }
            string temp = path.substr(pos, i - pos);
            if (temp == "." || temp == "") {
                continue;
            } else if (temp == "..") {
                if (directs.size()) {
                    directs.erase(directs.end() - 1);
                }
            } else {
                directs.push_back(temp);
            }
        }
        for (int i = 0; i < directs.size(); i++) {
            result += "/" + directs.at(i);
        }
        if (result == "") result += "/";
        return result;
    }
};


