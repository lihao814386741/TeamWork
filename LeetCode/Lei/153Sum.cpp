class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int number = int(nums.size());
    sort(nums.begin(),nums.end());
    vector<vector<int>> results;
     for(int i=0; i<number-2; i++)
     {
      if(i>0&&nums[i-1]==nums[i])
        continue;
      int a = nums[i];
      int low = i+1;
      int high = number-1;
      while(low<high)
      {
        int b = nums[low];
        int c = nums[high];
        if(a+b+c==0)
        {
          vector<int> v;
          v.push_back(a);
          v.push_back(b);
          v.push_back(c);
          results.push_back(v);
        
        while(low<number&&nums[low]==nums[low+1])
          low++;
        low++;
        while(high>0&&nums[high]==nums[high-1])
          high--;
        high--;
        }
        else if(a+b+c>0)
        {
          if(high>0&&nums[high]==nums[high-1])
            high--;
          high--;
        }
        else if(a+b+c<0)
        {
           if(low<number&&nums[low]==nums[low+1])
             low++;
           low++;
        }
      }
     }
     return results;
    }
};
