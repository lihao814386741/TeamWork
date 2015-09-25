/**
 * Divide and comquer questions. 
 * But then I found there are duplicate subproblmes. 
 * And trying to use backward&foreward DP. But I'm wrong because of *. Like(1+2*3+4);
 * To solve this duplicate problem, just use a memo which is implementd by hash;
 **/
 
class Solution {
public:
    // Assume that input is a valid expression without whitespace and other char.
    vector<int> diffWaysToCompute(string input) {
        if (memo.find(input) != memo.end()) {
            return memo[input];
        }
        
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            if (!isdigit(input.at(i))) {
                vector<int> first = diffWaysToCompute(input.substr(0, i));
                vector<int> second = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                vector<int> tmpRes = computeOperation(first, second, input.at(i));
                result.insert(result.end(), tmpRes.begin(), tmpRes.end());
            }
        }
        
        // No operator
        if (!input.empty() && result.empty()) {
            result.push_back(stoi(input));
        }
        memo[input] = result;
        return result;
    }
private:
    unordered_map<string, vector<int>> memo;
    
    vector<int> computeOperation(vector<int> &first, vector<int> &second, char operation) {
        assert(!first.empty() && !second.empty());
        vector<int> result;
        for (int i = 0; i < first.size(); ++i) {
            for (int j = 0; j < second.size(); ++j) {
                if (operation == '*') {
                    result.push_back(first.at(i) * second.at(j));
                } else if (operation == '+') {
                    result.push_back(first.at(i) + second.at(j));
                } else if (operation == '-') {
                    result.push_back(first.at(i) - second.at(j));
                }
            }
        }
        return result;
    }
};
