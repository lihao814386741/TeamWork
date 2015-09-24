class Solution {
public:
    int calculate(string s) {
        // Special case.
        if (s.empty()) {
            return 0;
        }
        
        vector<string> notation;
        toReversePolishNotation(s, notation);
        return calulateReversePolishNotation(notation);
    }
private: 
    // Transfer from normal notation to reverse polish notation
    void toReversePolishNotation(string s, vector<string> &notation) {
        stack<char> operStk;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int j = i + 1;
                while (isdigit(s[j])) ++j;
                notation.push_back(s.substr(i, j - i));
                i = j;
            } 
            
            // Trick is that string is end with '/0'
            if (s[i] == '+' || s[i] == '-' ) {
                while (!operStk.empty() && (operStk.top() != '(')) {
                    notation.push_back(string(1, operStk.top()));
                    operStk.pop();
                }
                operStk.push(s[i]);
            } else if (s[i] == '/' || s[i] == '*') {
                while (!operStk.empty() && (operStk.top() == '*' || operStk.top() == '/')) {
                    notation.push_back(string(1, operStk.top()));
                    operStk.pop();
                }
                operStk.push(s[i]);
            } else if (s[i] == ')') {
                while (!operStk.empty() && operStk.top() != '(') {
                    notation.push_back(string(1, operStk.top()));
                    operStk.pop();
                }
                if (!operStk.empty()) {
                    operStk.pop();
                }
            }
        }
        
        while (!operStk.empty()) {
            notation.push_back(string(1, operStk.top()));
            operStk.pop();
        }
    }
    
    // Calculate reverse polish notation
    int calulateReversePolishNotation(vector<string> &notation) {
        stack<int> stk;
        for (int i = 0; i < notation.size(); ++i) {
            cout << notation.at(i) << ',';
            if (notation.at(i) == "+") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(first + second);
            } else if (notation.at(i) == "-") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(second - first);
            } else if (notation.at(i) == "*") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(second * first);
            } else if (notation.at(i) == "/") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(second / first);
            } else {
                stk.push(stoi(notation.at(i)));
            }
        }
        return stk.top();
    }
};
