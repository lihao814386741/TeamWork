/**
 * Only computation, a little faster.
 **/ 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int total = (1 + n) * n / 2;
        for (int i = 0; i < n; i++) {
            total -= nums.at(i);
        }
        return total;
    }
};

/**
 * Hash version, a little slower.
 **/ 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        unordered_map<int, int> records;
        for (int i = 0; i < n; i++) 
            records[nums.at(i)] = 1;
        for (int i = 0; i <= n; i++) {
            if (!records.count(i))
                return i;
        }
    }
};