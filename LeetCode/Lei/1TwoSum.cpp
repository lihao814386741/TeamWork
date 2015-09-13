class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        for(int i=0; i<int(nums.size()); i++)
        {
          if(m.find(nums[i])==m.end())
          {
            m[target-nums[i]]=i;
          }
          else
          {
            result.push_back(m[nums[i]]+1);
            result.push_back(i+1);
            break;
          }
        }
    return result;
    }
};
