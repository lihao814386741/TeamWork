/**
 * Special thanks for these two posts:
 * 1. C++: https://leetcode.com/discuss/44689/10-lines-c-code-8-ms-passed
 * 2. Java: https://leetcode.com/discuss/46948/accepted-java-easy-to-understand-solution
 **/

enum State : int8_t {UNFOUND = 0, APPEARED = 1, ADDED = 2};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) {
            return vector<string>();
        }
        
        int maxNum = pow(4, 10);
        vector<State> hash(maxNum, UNFOUND);
        vector<string> result;
        
        // Generate the first 10-length string hash
        int key = 0;
        for (int i = 0; i < 10; ++i) {
            key = key * 4 + transfer(s.at(i)); 
        }
        hash.at(key) = APPEARED;
        
        for (int i = 10; i < s.size(); ++i) {
            key = (key * 4) % maxNum + transfer(s.at(i));
            if (hash.at(key) == APPEARED) {
                hash.at(key) = ADDED;
                result.push_back(s.substr(i - 9, 10));
            } else if (hash.at(key) == UNFOUND) {
                hash.at(key) = APPEARED;
            }
        }
        return result;
    }
    
private:
    int transfer(char nucleotide) {
        switch(nucleotide) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
            default:
                throw("DNA input error!");
                return -1;
        }
    }
};
