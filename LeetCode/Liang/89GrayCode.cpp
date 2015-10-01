iclass Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        for (int i = 0; i < n; ++i) {
            int last = result.size() - 1;
            for (int j = last; j >= 0; --j) {
                result.push_back(result.at(j) | 1 << i);
            }
        }
        return result;
    }
};
