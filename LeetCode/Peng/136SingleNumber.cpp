//hash_map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        unordered_map<int, int> records;
        for (int i = 0; i < n; i++) {
            int current = nums.at(i);
            if (records.count(current))
                records.erase(current);
            else
                records[current] = 1;
        }
        unordered_map<int, int>::iterator iter = records.begin();
        return iter->first;
        
    }
};

//XOR 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums.at(0) ^= nums.at(i);
        }
        return nums.at(0);
    }
};