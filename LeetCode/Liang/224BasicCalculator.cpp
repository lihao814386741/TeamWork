/**
 * Right now, I can only do it in a simple way. => Reverse Polish notation => calculate;
 * Not totally understand this: 
 * https://leetcode.com/discuss/53921/16-ms-solution-in-c-with-stacks
 **/
 
class Solution {
public:
    int calculate(string s) {
        stack<char> stk;
        vector<string> notation;
        int idx = 0;
        
        // Transfer to reverse polish notation
        while (idx < s.size()) {
            if (isdigit(s[idx])) {
                int j = idx;
                while (isdigit(s[j])) ++j;
                notation.push_back(s.substr(idx, j - idx));
                idx = j - 1;
            } else if (s[idx] == '(') {
                stk.push('(');
            } else if (s[idx] == '+' || s[idx] == '-') {
                if (!stk.empty() && stk.top() != '(') {
                    notation.push_back(string(1, stk.top()));
                    stk.pop();
                } 
                stk.push(s[idx]);
            } else if (s[idx] == ')') {
                while (stk.top() != '(') { // speical case (4)
                    notation.push_back(string(1, stk.top()));
                    stk.pop();
                }
                stk.pop();
            }
            ++idx; // Forget and put in the wrong place.
        }
        
        while (!stk.empty()) { // Finally operator in stack;
            notation.push_back(string(1, stk.top()));
            stk.pop();
        }
        
        // Calculate the result
        int result = 0;
        stack<int> numStk;
        for (int i = 0; i < notation.size(); ++i) {
            if (notation.at(i) == "+") {
                int first = numStk.top();
                numStk.pop();
                int second = numStk.top();
                numStk.pop();
                numStk.push(first + second);
            } else if (notation.at(i) == "-") {
                int first = numStk.top();
                numStk.pop();
                int second = numStk.top();
                numStk.pop();
                numStk.push(second - first);
            } else {
                // Assume to_string() will not overflow. 
                // stoi : invalid_argument and out_of_range exception
                numStk.push(stoi(notation.at(i)));
            }
        }
        
        return numStk.top();
    }
};
