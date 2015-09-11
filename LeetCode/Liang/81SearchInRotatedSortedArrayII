ass Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (target == nums.at(mid)) {
                return true;
            }
            
            if (nums.at(mid) > nums.at(end)) {
                if (target < nums.at(mid) && target >= nums.at(begin)) {
                    end = mid;
                } else {
                    begin = mid + 1;
                }
            } else if (nums.at(mid) < nums.at(end)) {
                if (target > nums.at(mid) && target <= nums.at(end)) {
                    begin = mid + 1;
                } else {
                    end = mid;
                }
            } else if (nums.at(mid) == nums.at(end)) {
                --end;
            }
        }
        
        if (target == nums.at(begin)) {
            return true;
        }
        
        return false;
    }
};
