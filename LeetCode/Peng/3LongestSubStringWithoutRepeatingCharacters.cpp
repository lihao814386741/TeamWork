class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> window;
        int length = 0;
        int begin = 0;
        for (int i = 0; i < n; i++) {
            char temp = s.at(i);
            if (!window.count(temp)) {
                window[temp] = 1;
                continue;
            }
            length = max(length, i - begin);
            while (s.at(begin) != temp) {
                window.erase(s.at(begin));
                begin++;
            }
            begin++;
        }
        return max(length, n - begin);
    }
};

//array is much faster
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int length = 0;
        int begin = 0;
        char window[256] = {0};
        for (int i = 0; i < n; i++) {
            char temp = s.at(i);
            if (!window[temp]) {
                window[temp]++;
                continue;
            }
            length = max(length, i - begin);
            while (s.at(begin) != temp) {
                window[s.at(begin)]--;
                begin++;
            }
            begin++;
        }
        return max(length, n - begin);
    }
};