class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        // Special case
        if (beginWord == endWord) {
            return 1;
        }
        
        queue<pair<string, int>> strStep; // It's not queue<string, int>
        strStep.push(make_pair(beginWord, 1));
        wordList.erase(beginWord);
        while (!strStep.empty()) {
            pair<string, int> front = strStep.front();
            strStep.pop();
            for (int i = 0; i < front.first.size(); ++i) {
                string tmpStr = front.first;
                for (int j = 0; j < 27; ++j) {
                    tmpStr[i] = 'a' + j;
                    if (tmpStr == endWord) {
                        return front.second + 1;
                    }
                    
                    if (wordList.find(tmpStr) != wordList.end()) {
                        strStep.push(make_pair(tmpStr, front.second + 1));
                        wordList.erase(tmpStr);
                    }
                }
            }
        }
        return 0;
    }
};
