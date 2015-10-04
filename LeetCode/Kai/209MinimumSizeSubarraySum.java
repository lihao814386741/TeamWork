//O(n)
public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int p1 = 0;
        int p2 = 0;
        int sum = 0;
        int minLen = Integer.MAX_VALUE;
        while(p1<=p2) {
            if(sum<s) {
                if(p2==nums.length) break;
                sum += nums[p2];
                p2++;
            } else {
                minLen = Math.min(minLen, p2-p1);
                sum -= nums[p1];
                p1++;
            }
        }
        
        return minLen==Integer.MAX_VALUE ? 0:minLen;
    }
    
}


//nlogn
//Use sum[i]
//serach for sum[i] - target + 1 in nums[0] to nums[i]