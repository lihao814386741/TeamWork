ass Solution {
public:
    string simplifyPath(string path) {
        vector<string> elemStk;
        int i = 0;
        while (i < path.size()) {
            int j = i + 1;
            while (j < path.size() && path[j] != '/') ++j;
            string element = path.substr(i, j - i);
            i = j;
            if (element == "/." || element == "/") {
                continue;
            } else if (element == "/..") {
                if (!elemStk.empty()) {
                    elemStk.pop_back();   
                }
            } else {
                elemStk.push_back(element);
            }
        }
        
        string result;
        for (i = 0; i < elemStk.size(); ++i) {
            result += elemStk.at(i);   
        }
        // Speical case
        if (result.empty() && !path.empty()) {
            result = "/";
        }
        return result;
    }
};
