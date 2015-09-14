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
};
