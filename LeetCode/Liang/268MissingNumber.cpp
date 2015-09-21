/**
 * Basically, XOR, SUM, time spend almost the same;
 **/
 
class Solution {
public:
    int missingNumberXOR(vector<int>& nums) {
        assert(!nums.empty());
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result ^= i ^ nums.at(i);
        }
        return result;
    }
    
    int missingNumber(vector<int> &nums) {
        assert(!nums.empty());
        long long result = (nums.size() + 1) * nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i) {
            result -= nums.at(i);
        }
        return result;
    }
};
