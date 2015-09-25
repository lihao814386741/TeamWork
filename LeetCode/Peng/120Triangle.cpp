class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int path = INT_MAX;
        int n = triangle.size();
        vector<vector<int>> counter(triangle);
        for (int row = 1; row < n; row++) {
            for (int column = 0; column <= row; column++) {
                if (column == 0)
                    counter.at(row).at(column) += counter.at(row - 1).at(column);
                else if (column == row)
                    counter.at(row).at(column) += counter.at(row - 1).at(column - 1);
                else
                    counter.at(row).at(column) += min(counter.at(row - 1).at(column), counter.at(row - 1).at(column - 1));
            }
        }
        for (int i = 0; i < n; i++)
            path = min(path, counter.at(n - 1).at(i));
        return path;
    }
};

//less space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (!triangle.size()) return 0;
        int path = INT_MAX;
        int n = triangle.size();
        vector<int> counter(n, 0);
        counter.at(0) = triangle.at(0).at(0);
        for (int row = 1; row < n; row++) {
            for (int column = row; column >= 0; column--) {
                if (column == 0)
                    counter.at(column) += triangle.at(row).at(column);
                else if (column == row)
                    counter.at(column) = triangle.at(row).at(column) + counter.at(column - 1);
                else
                    counter.at(column) = triangle.at(row).at(column) + min(counter.at(column - 1), counter.at(column));
            }
        }
        for (int i = 0; i < n; i++)
            path = min(path, counter.at(i));
        return path;
    }
};