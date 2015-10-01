class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        if (s.empty()) {
            return vector<string>();
        }
        vector<vector<int>> graph;
        graphGenerater(s, wordDict, graph);
        
        string path;
        vector<string> result;
        wordBreakDFSHelper(s, s.size(), graph, path, result);
        return result;
    }
    
    // A way to generate graph.
    void graphGenerater(string s, unordered_set<string> &wordDict, vector<vector<int>> &graph) {
        graph.assign(s.size() + 1, vector<int>()); // vector.assign(); is new to me.
        graph.at(0).push_back(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (graph.at(i).empty()) { // Forget this.
                continue;
            }
            
            for (int j = 1; i + j <= s.size(); ++j) {
                if (wordDict.find(s.substr(i, j)) != wordDict.end()) {
                    graph.at(i + j).push_back(i);
                }
            }
        }
    }
    
    // DFS result gernerater
    void wordBreakDFSHelper(string &s, int current, vector<vector<int>> &graph, string &path, vector<string> &result) {
        if (current == 0) {
            assert(!path.empty());
            result.push_back(path.substr(1));
            return;
        }
        
        vector<int> parent = graph.at(current);
        for (int pre : parent) {
            path = ' ' + s.substr(pre, current - pre) + path;
            wordBreakDFSHelper(s, pre, graph, path, result);
            path = path.substr(current - pre + 1);
        }
    }
};
