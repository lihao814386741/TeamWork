//After we sorted the vector,we will know that all the paper that after //i will have the same or more citations.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int result = 0;
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; i++) {
            result = max(result, min(n - i, citations.at(i)) );
        }
        return result;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int result = 0;
        vector<int> count(n + 2, 0);
        for (int i = 0; i < n; i++) {
            if (citations.at(i) > n) {
                count.at(n)++;
            } else {
                count.at(citations.at(i))++;
            }
        }
        for (int i = n; i >= 0; i--) {
            count.at(i) += count.at(i + 1);
            if (count.at(i) >= i) {
                result = i;
                break;
            }
        }
        return result;
    }
};