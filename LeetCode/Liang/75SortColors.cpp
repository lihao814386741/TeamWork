/**
 * 1. Counting sort
 * 2. Two pointer
 **/

enum Color : int { RED = 0, WHITE = 1, BLUE = 2 };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIdx = 0, test = 0, twoIdx = (int)nums.size() - 1;
        while (test <= twoIdx) {
            if (nums.at(test) == RED) {
                swap(nums.at(test), nums.at(zeroIdx));
                ++test;
                ++zeroIdx;
            } else if (nums.at(test) == WHITE) {
                ++test;
            } else if (nums.at(test) == BLUE) {
                swap(nums.at(test), nums.at(twoIdx));
                --twoIdx;
            }
        }
    }
}; 
