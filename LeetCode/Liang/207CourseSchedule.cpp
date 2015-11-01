class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph;
        generateGraph(numCourses, prerequisites, graph);
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        for (int i = 0; i < numCourses; ++i) { // Not numCourses.
            if (!visited.at(i) && hasCircleDFS(graph, i, visited, path)) {
                // If it's an unvisited DFS tree. Then test it.
                return false;
            }
        }
        return true;
    }
    
private:
    void generateGraph(const int numCourses, const vector<pair<int, int>> &prerequisites, vector<vector<int>> &graph) {
        graph.assign(numCourses, vector<int>());
        for (const pair<int, int> &current : prerequisites) {
            graph.at(current.first).push_back(current.second); // Not ->
        }
    }
    
    bool hasCircleDFS(vector<vector<int>> &graph, int current, vector<bool> &visited, vector<bool> &path) {
        // Base cases.
        if (path.at(current)) {
            return true;
        }
        
        if (visited.at(current)) {
            return false;
        }
        visited.at(current) = true;
        
        path.at(current) = true;
        for (int i : graph.at(current)) {
            if (hasCircleDFS(graph, i, visited, path)) {
                return true;
            }
        }
        path.at(current) = false;
        return false;
    }
};
