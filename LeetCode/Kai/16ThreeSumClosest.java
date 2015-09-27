//two pointers
public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = 0;
        int min = Integer.MAX_VALUE;
        for(int i=0; i<nums.length-2; i++) {
            int j = i+1;
            int k = nums.length-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return sum;
                int diff = Math.abs(sum-target);
                if(diff<min) {
                    min = diff;
                    result = sum;
                }
                if(sum<target) j++;
                else if(sum>target) k--;
            }
        }
        return result;
    }
    
}