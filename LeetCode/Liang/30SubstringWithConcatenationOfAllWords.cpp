/**
 * It indeed likes Minimum Window Substring. But if the words are not the same length, it's another story.
 * Special thanks to:
 * 1. https://leetcode.com/discuss/50395/my-36ms-c-solution-o-n-time-using-an-unordered_map
 **/
 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || words.at(0).empty() || s.empty()) {
            return vector<int>();
        }
        
        // generate dict;
        unordered_map<string, int> dict;
        generateDictionary(words, dict);
        
        // generate result;
        int wordLen = words.at(0).size();
        int num = words.size();
        vector<int> result;
        for (int i = 0; i < wordLen; ++i) {
            findSubstringWithStartPositionHelper(s, num, i, wordLen, dict, result);
        }
        return result;
    }
    
private:
    void generateDictionary(const vector<string> &words, unordered_map<string, int> &dict) {
        for (string word : words) {
            ++dict[word];
        }
    }
    
    void findSubstringWithStartPositionHelper(const string s, int num, int start, const int wordLen, unordered_map<string, int> dict, vector<int> &result) {
        assert(start >= 0 && start < wordLen);
        int left = 0, right = 0;
        for (; right < s.size() / wordLen; ++right) {
            string currentWord = s.substr(start + right * wordLen, wordLen);
            if (dict.find(currentWord) != dict.end()) {
                --dict[currentWord];
                if (dict[currentWord] >= 0) {
                    --num;
                } else {
                    // Shrimp the left boudary to make dict[currentWord] == 0.
                    while (dict[currentWord] != 0) {
                        string leftBoundary = s.substr(start + left * wordLen, wordLen);
                        ++dict[leftBoundary];
                        ++left;
                        ++num; // Forgot this.
                    }
                    --num; // This is tricky.
                }
            } else {
                // Shrimp to the left boundary to right + 1;
                while (left < right) {
                    string leftBoundary = s.substr(start + left * wordLen, wordLen);
                    ++dict[leftBoundary];
                    ++left;
                    ++num; // Forgot this;
                }
                ++left;
            }
            
            // cout << left << "," << right << ": " << num << endl;
            if (num == 0) {
                result.push_back(start + left * wordLen); // Not left it self;
                // Shrimp left boundary to one unit.
                string leftBoundary = s.substr(start + left * wordLen, wordLen);
                ++dict[leftBoundary];
                ++left;
                ++num; // Forgot this.
            }
        }
    }
};
