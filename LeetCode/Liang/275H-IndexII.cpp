class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Special case: [0], [0, 0];
        if (!citations.empty() && citations.back() == 0) {
            return 0;
        }
        
        int begin = 0, end = citations.size() - 1, total = citations.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (total - mid > citations.at(mid)) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return total - begin;
    }
};
