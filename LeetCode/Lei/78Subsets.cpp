class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>> allsets;
     vector<int> set;
     allsets.push_back(set);
     sort(nums.begin(),nums.end());
     for(int i=0; i<int(nums.size()); i++)
     {
       int n = int(allsets.size());
       for(int j=0; j<n; j++)
       {
         set=allsets[j];
         set.push_back(nums[i]);
         allsets.push_back(set);
       }
     }
    return allsets;
  }
};
