ass Solution {
public:
    void reverseWords(string &s) {
        stringPreprocessHelper(s);
        size_t i = 0;
        while (i < s.size()) {
            size_t j = s.find_first_of(' ', i);
            if (j != string::npos) {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            } else {
                reverse(s.begin() + i, s.end());
                break;
            }
        }
        reverse(s.begin(), s.end());
    }
private:
    void stringPreprocessHelper(string &s) {
        int first = 0, second = 0; 
        while (second < s.size()) {
            if (s[second] != ' ' || (first > 0 && s[first - 1] != ' ')) {
                s[first] = s[second];
                ++first;
            }
            ++second;
        }
        
        if (first > 0 && s[first - 1] == ' ') {
            --first;
        }
        s.resize(first);
    }
};
