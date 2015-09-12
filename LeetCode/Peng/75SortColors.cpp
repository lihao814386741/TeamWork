class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int two = n - 1;
        int current = 0;
        while (current <= two) {
            if (nums.at(current) == 2) {
                swap(nums.at(current), nums.at(two));
                two--;
            } else {
                if (nums.at(current) == 0) {
                    swap(nums.at(current), nums.at(zero));
                    zero++;
                }
                current++;
            }
        }
    }
};