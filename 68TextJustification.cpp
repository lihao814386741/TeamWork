/**
 * It assumes that word.size() < maxWidth.
 * Special thanks to: 
 * 1. https://leetcode.com/discuss/30857/share-my-2-ms-30-lines-solution
 **/
 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int begin = 0;
        vector<string> result;
        while (begin < words.size()) {
            int test = begin + 1;
            int lineLen = words.at(begin).size();
            while (test < words.size() && lineLen + 1 + words.at(test).size() <= maxWidth) {
                lineLen += 1 + words.at(test).size(); // Forgot the 1 inside.
                ++test;
            }
            
            int space = 1, extra = 0;
            if (test > begin + 1 && test != words.size()) { // If it's the last line.
                space = (maxWidth - lineLen) / (test - begin - 1) + 1;
                extra = (maxWidth - lineLen) % (test - begin - 1);  
            }
            
            result.push_back(words.at(begin));
            ++begin;
            
            while (begin < test) {
                if (extra > 0) {
                    result.back().append(1, ' ');
                    --extra;
                }
                result.back().append(space, ' ');
                result.back().append(words.at(begin));
                ++begin;
            }
            result.back().append(maxWidth - result.back().size(), ' '); // If only have one word in a line.
        }
        return result;
    }
};
