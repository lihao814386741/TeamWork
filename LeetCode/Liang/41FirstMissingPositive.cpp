/**
 * It's tricky when 0 is inside. My method will put 0 as negative numbers.
 **/
 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Like quick sort move positive numbers to the front;
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            if (nums.at(begin) <= 0) {
                swap(nums.at(begin), nums.at(end));
                --end;
            } else {
                ++begin;
            }
        }
        
        // Change value.
        for (int i = 0; i <= end; ++i) {
            int index = abs(nums.at(i)) - 1;
            if (index <= end && index >= 0) {
                nums.at(index) = -abs(nums.at(index));
            }
        }
        
        for (int i = 0; i <= end; ++i) {
            if (nums.at(i) > 0) {
                return i + 1;
            }
        }
        
        return end + 2;
    }
};
