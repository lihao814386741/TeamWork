/**
 * It's just like upper_bound and lower_bound [ , )
 **/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result(2, -1);
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        if (lower < upper) {
            result.at(0) = lower;
            result.at(1) = upper - 1;
        }
        return result;
    }
    
private:
    // Find the first element index that is no less than target.
    int lowerBound(const vector<int> &nums, int target)
    {
        if (nums.empty()) {
            return -1;
        }
        
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (target <= nums.at(mid)) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        
        // Because of case: [1, 1], 2
        if (target > nums.at(begin)) {
            ++begin;
        }
        return begin;
    }
    
    // Find the first element index that is larget than target.
    int upperBound(const vector<int> &nums, int target)
    {
        if (nums.empty()) {
            return -1;
        }
        
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (target >= nums.at(mid)) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        
        // Because of case: [1, 1], 2
        if (target == nums.at(begin)) {
            ++begin;
        }
        
        return begin;
    }
};