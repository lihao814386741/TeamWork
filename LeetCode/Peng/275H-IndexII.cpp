//Compare the number of papers and the number of citations.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int result = 0;
        int n = citations.size();
        int begin = 0;
        int end = n - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (n - mid > citations.at(mid)) {
                result = max(result, citations.at(mid));
                begin = mid + 1;
            } else {
                result = max(result, n- mid);
                end = mid - 1;
            }
        }
        return result;
    }
};

//When #paper == #citations, we got the answer
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int begin = 0;
        int end = n - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (n - mid == citations.at(mid)) {
                return n - mid;
            } else if (n - mid > citations.at(mid)) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return n - begin;
    }
};