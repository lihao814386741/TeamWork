/**
 * 1. To three sum.
 * 2. To 2 two sum.
 **/
 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < (int)nums.size() - 3; ++i) {
            if (i == 0 || nums.at(i) != nums.at(i - 1)) {
                for (int j = i + 1; j < (int)nums.size() - 2; ++j) {
                    if (j == i + 1 || nums.at(j) != nums.at(j - 1)) {
                        int sum = nums.at(i) + nums.at(j);
                        int begin = j + 1, end = nums.size() - 1;
                        while (begin < end) {
                            int tmpSum = sum + nums.at(begin) + nums.at(end);
                            if (tmpSum == target) {
                                vector<int> tmpVtor = {nums.at(i), nums.at(j), nums.at(begin), nums.at(end)};
                                result.push_back(tmpVtor);
                                while (begin < end && nums.at(begin) == nums.at(begin + 1)) ++begin;
                                ++begin;
                                
                                while (begin < end && nums.at(end) == nums.at(end - 1)) --end;
                                --end;
                            } else if (tmpSum > target) {
                                --end;
                            } else {
                                ++begin;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};
