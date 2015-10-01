class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        assert(nums.size() >= 2);
        int aXORb = 0; // Use 0 is fine.
        for (int i = 0; i < nums.size(); ++i) {
            aXORb ^= nums.at(i);
        }
        int lastDiff = (aXORb & (aXORb - 1)) ^ aXORb;
        int first = 0, second = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (lastDiff & nums.at(i)) {
                first ^= nums.at(i);
            } else {
                second ^= nums.at(i);
            }
        }
        return vector<int>{first, second};
    }
};
