/**
 * Use stack to re-construct string, OR use vector<pairs> to record the
 * words positions.
 **/ 
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        stack<string> words;
        for (int i = 0; i < n; i++) {
            while (i < n && s.at(i) == ' ') {
                i++;
            }
            int pos = i;
            while (i < n && s.at(i) != ' ') {
                i++;
            }
            if (i - pos) {
                words.push(s.substr(pos, i - pos));
            }
        }
        string result = "";
        while (!words.empty()) {
            result += words.top();
            words.pop();
            while (!words.empty()) {
                result += " " + words.top();
                words.pop();
            }
        }
        s = result;
    }
};