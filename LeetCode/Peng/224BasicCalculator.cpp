/**
 * Recursive version
 *   - Do computation for each pair of parentheses.
 **/ 
class Solution {
public:
    int helper(string& s, int& pos) {
        int n = s.size();
        int result = 0, temp = 0, flag = 1;
        for (; pos < n; pos++) {
            if (s.at(pos) == ' ') {
                continue;
            } else if (s.at(pos) == '(') {
                result += helper(s, ++pos) * flag;
            } else if(s.at(pos) >= '0' && s.at(pos) <= '9') {
                temp = temp * 10 + (s.at(pos) - '0');
            } else {
                result += temp * flag;
                temp = 0;
                flag = 1;
                if (s.at(pos) == ')') {
                    break;
                } else if (s.at(pos) == '-') {
                    flag = -1;
                }
            }
        }
        if (temp) {
            result += temp * flag;
        }
        return result;
    }

    int calculate(string s) {
        int pos = 0;
        return helper(s, pos);
    }
};


/**
 * Iterative version
 *   - Save the state in a stack before enter a pair of parentheses.
 **/ 
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int result = 0, temp = 0, flag = 1;
        stack<int> nums;
        for (int pos = 0; pos < n; pos++) {
            if (s.at(pos) == ' ') {
                continue;
            } if (s.at(pos) == '(') {
                nums.push(result);
                nums.push(flag);
                result = 0;
                flag = 1;
            } else if(s.at(pos) >= '0' && s.at(pos) <= '9') {
                temp = temp * 10 + (s.at(pos) - '0');
            } else {
                result += temp * flag;
                temp = 0;
                flag = 1;
                if (s.at(pos) == ')') {
                    result *= nums.top();
                    nums.pop();
                    result += nums.top();
                    nums.pop();
                } else if (s.at(pos) == '-') {
                    flag = -1;
                }
            }
        }
        if (temp) {
            result += temp * flag;
        }
        return result;
    }
};