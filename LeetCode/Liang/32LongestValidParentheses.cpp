/**
 * Think about this method:
 * https://leetcode.com/discuss/53758/constant-space-o-n-time-with-forward-and-backward-pass
 **/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int lastInvalidClose = -1;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                    if (stk.empty()) {
                        maxLen = max(maxLen, i - lastInvalidClose);
                    } else {
                        maxLen = max(maxLen, i - stk.top());   
                    }
                } else {
                    lastInvalidClose = i;
                }
            }
        }
        return maxLen;
    }
};
