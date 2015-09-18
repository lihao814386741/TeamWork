class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> res;  
        int numlen = nums.size();  
        if(nums.size()<4)return res;  
          
        sort(nums.begin(),nums.end());  
        set<vector<int>> tmpres;  
        for(int i = 0; i < numlen; i++)  
        {  
            for(int j = i+1; j < numlen; j++)  
            {  
                int begin = j+1;  
                int end = numlen-1;  
                while(begin < end)  
                {  
                    int sum = nums[i]+ nums[j] + nums[begin] + nums[end];  
                    if(sum == target)  
                    {  
                        vector<int> tmp;  
                        tmp.push_back(nums[i]);  
                        tmp.push_back(nums[j]);  
                        tmp.push_back(nums[begin]);  
                        tmp.push_back(nums[end]);  
                        tmpres.insert(tmp);  
                        begin++;  
                        end--;  
                    }else if(sum<target)  
                        begin++;  
                    else  
                        end--;  
                }  
            }  
        }  
        set<vector<int>>::iterator it = tmpres.begin();  
        for(; it != tmpres.end(); it++)  
            res.push_back(*it);  
        return res;  
    }
};