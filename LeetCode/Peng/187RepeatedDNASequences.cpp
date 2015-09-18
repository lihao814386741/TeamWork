//use hash
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> result;
        if (n <= 10) return result;
        unordered_map<char, int> symbolMapping = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> seqCounter;
        int bitmap = 0;
        for (int i = 0; i < 9; i++) {
    		bitmap = bitmap << 2 | symbolMapping.at(s.at(i));
    	}
        for (int i = 9; i < n; i++) {
            bitmap = bitmap << 2 & 0xfffff | symbolMapping.at(s.at(i));
            if (seqCounter.count(bitmap)) {
                if (seqCounter.at(bitmap)++ == 1) {
                    result.push_back(s.substr(i - 9, 10));
                }
            }
            else
                seqCounter[bitmap] = 1;
        }
        return result;
    }
};

//vector will use more memory than array[], lead to MLE
//Do (s[i] - 'A' + 1) % 5  is faster than read a mapping in a map?
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> result;
        if (n <= 10) return result;
        int seqCounter[1048576]  = {0};
        int bitmap = 0;
        for (int i = 0; i < 9; i++) {
    		bitmap = bitmap << 2 | (s[i] - 'A' + 1) % 5;
    	}
        for (int i = 9; i < n; i++) {
            bitmap = bitmap << 2 & 0xfffff | (s[i] - 'A' + 1) % 5;
            if (seqCounter[bitmap]++ == 1) {
                    result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};