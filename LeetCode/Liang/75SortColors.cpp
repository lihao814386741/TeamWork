/**
 * 1. Counting sort
 * 2. Two pointer
 **/
 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIdx = 0, test = 0, twoIdx = (int)nums.size() - 1;
        while (test <= twoIdx) {
            if (nums.at(test) == 0) {
                swap(nums.at(test), nums.at(zeroIdx));
                ++test;
                ++zeroIdx;
            } else if (nums.at(test) == 1) {
                ++test;
            } else if (nums.at(test) == 2) {
                swap(nums.at(test), nums.at(twoIdx));
                --twoIdx;
            }
        }
    }
};
