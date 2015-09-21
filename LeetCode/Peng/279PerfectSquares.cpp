//Grow ideal, add square numbers
class Solution {
public:
    int numSquares(int n) {
        vector<int> records(n + 1, INT_MAX);
        for (int i = 1; i * i <= n; i++) {
            records[i * i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; i + j * j <= n; j++) {
                records[i + j * j] = min(records[i + j * j], records[i] + 1);
            }
        }
        return records[n];
    }
};