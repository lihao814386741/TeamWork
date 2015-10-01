/**
 * Yes back to the curcuit design:
 * https://leetcode.com/discuss/54970/an-general-way-to-handle-all-this-sort-of-questions
 **/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = (one & ~two & nums.at(i)) | (~one & two & ~nums.at(i));
            one = (~one & ~two & nums.at(i)) | (one & ~two & ~nums.at(i));
            two = tmp;
        }
        return one | two; // if it appear one time, it will be stored in one; otherwise, two;
    }
};
