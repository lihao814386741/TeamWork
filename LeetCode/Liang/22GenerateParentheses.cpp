/**
 * Question:
 * What's the time complexity and space complexity.
 **/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
       if (n == 0) {
           return vector<string>();
       }
       
       string path;
       vector<string> result;
       DFSHelper(n, 0, 0, path, result);
       return result;
    }
private:
    void DFSHelper(const int n, int left, int right, string &path, vector<string> &result) {
        if (right == n) {
            result.push_back(path);
            return;
        }
        
        if (left < n ) {
            path += '(';
            DFSHelper(n, left + 1, right, path, result);
            path.pop_back();
        }
        
        if (right < left) {
            path += ')';
            DFSHelper(n, left, right + 1, path, result);
            path.pop_back();
        }
    }
};
