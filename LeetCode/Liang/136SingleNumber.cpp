class Solution {
public:
    int singleNumber(vector<int>& nums) {
        assert(!nums.empty());
        int singleNumber = nums.at(0);
        for (int i = 1; i < nums.size(); ++i) {
            singleNumber ^= nums.at(i);
        }
        return singleNumber;
    }
};
