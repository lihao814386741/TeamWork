class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //two same number xor equal to 0
        int s=0;
        for(int i=0; i<nums.size(); i++)
        {
          s=s^nums[i];
        }
    return s;
    }
};
