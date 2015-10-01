class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> graph;
        vector<vector<string>> result;
        vector<string> path;
        generateGraph(s, graph);
        generatePartitionDFS(s, graph, 0, path, result);
        return result;
    }
    
private:
    void generateGraph(string &s, vector<vector<bool>> &graph) {
        graph.assign(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i) {
                    graph.at(i).at(j) = true;
                } else if (j == i - 1) {
                    graph.at(i).at(j) = (s[i] == s[j]);
                } else {
                    graph.at(i).at(j) = (s[i] == s[j] && graph.at(i - 1).at(j + 1));
                }
            }
        }
    }
    
    void generatePartitionDFS(string &s, vector<vector<bool>> &graph, int step, vector<string> &path, vector<vector<string>> &result) {
        if (step == s.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = step; i < s.size(); ++i) {
            if (!graph.at(i).at(step)) { // Be careful. The graph is from j to i;
                continue;
            }
            
            path.push_back(s.substr(step, i - step + 1));
            generatePartitionDFS(s, graph, i + 1, path, result);
            path.pop_back();
        }
    }
};
