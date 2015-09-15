class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        assert(s.size() <= INT_MAX);
        int localMax = 0, globalMax = 0;
        
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); ++i) {
            if (hash.find(s.at(i)) != hash.end()) {
                int tmpIdx = hash[s.at(i)];
                if (tmpIdx >= i - localMax) {
                    localMax = i - tmpIdx;
                } else {
                    ++localMax;
                }
            } else {
                ++localMax;
            }
            hash[s.at(i)] = i;
            
            globalMax = max(localMax, globalMax);
        }
        return globalMax;
    }
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        assert(s.size() <= INT_MAX);
        int globalMax = 0;
        // left is the left bound of the window while right is the right bound.
        int left = 0, right = 0;
        
        unordered_map<char, int> hash;
        for (; right < s.size(); ++right) {
            if (hash.find(s.at(right)) != hash.end()) {
                int tmp = hash[s.at(right)];
                if (tmp >= left) {
                    left = tmp + 1;
                }
            }
            
            hash[s.at(right)] = right;
            globalMax = max(globalMax, right - left + 1);
        }
        
        return globalMax;
    }
};
