/*
 * Iterative
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int begin = 0;
        int end = n - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            int current = nums.at(mid);
            if (current == target) return mid;
            else {
                if (current >= nums.at(begin)) {
                    if (target >= nums.at(begin) && target < current)
                        end = mid - 1;
                    else
                        begin = mid + 1;
                } else {
                    if (target > current && target <= nums.at(end))
                        begin = mid + 1;
                    else
                        end = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*
 * Recursive
 */
class Solution {
public:
    bool helper(vector<int>& nums, int begin, int end, int target) {
        if (begin > end) return false;
        
        int mid = begin + (end - begin) / 2;
        int current = nums.at(mid);
        if (current == target) return true;
        else if (current == nums.at(begin))
            return helper(nums, begin, mid - 1, target) || helper(nums, mid + 1, end, target);
        else {
            if (current >= nums.at(begin)) {
                if (target >= nums.at(begin) && target < current)
                    return helper(nums, begin, mid - 1, target);
                else
                    return helper(nums, mid + 1, end, target);
            } else {
                if (target > current && target <= nums.at(end))
                    return helper(nums, mid + 1, end, target);
                else
                    return helper(nums, begin, mid - 1, target);
            }
        }
    }
    bool search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};
