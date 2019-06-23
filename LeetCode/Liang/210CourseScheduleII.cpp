ss Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph;
        generateGraph(numCourses, prerequisites, graph);
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (findOrderHelper(graph, i, visited, path)) {
                return vector<int>();
            }
        }
        reverse(_result.begin(), _result.end());
        return _result;
    }
private:
    vector<int> _result;
    
    void generateGraph(const int numCourses, const vector<pair<int, int>> &prerequisites, vector<vector<int>> &graph) {
        graph.assign(numCourses, vector<int>());
        for (const pair<int, int> &current : prerequisites) {
            graph.at(current.second).push_back(current.first);
        }
    }
    
    bool findOrderHelper(const vector<vector<int>> &graph, int current, vector<bool> &visited, vector<bool> &path) {
        if (path.at(current)) {
            return true;
        }
        
        if (visited.at(current)) {
            return false;
        }
        
        visited.at(current) = true;
        path.at(current) = true;
        
        for (int next : graph.at(current)) {
            if (findOrderHelper(graph, next, visited, path)) {
                return true;
            }
        }
        
        _result.push_back(current);
        path.at(current) = false;
        return false;
    }
};
