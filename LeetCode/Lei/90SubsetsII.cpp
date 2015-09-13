class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allsets;
        vector<int> set;
        vector<vector<int>> this_layer;
        allsets.push_back(set);
        sort(nums.begin(),nums.end());
        for(int i=0; i<int(nums.size()); i++)
        {
          if(i>0&&nums[i-1]==nums[i])
          {
              vector<vector<int>> this_layer_new;
              for(int j=0; j<int(this_layer.size()); j++)
              {
                set=this_layer[j];
                set.push_back(nums[i]);
                this_layer_new.push_back(set);
                allsets.push_back(set);
              }
              this_layer=this_layer_new;
          }
          else
          {
              this_layer.clear();
              for(int j=0; j<int(allsets.size()); j++)
              {
                set=allsets[j];
                set.push_back(nums[i]);
                this_layer.push_back(set);
                allsets.push_back(set);
              }
          }
        }
    return allsets;
    }
};
