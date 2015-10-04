public class Solution {
    public void nextPermutation(int[] nums) {
        int p = -1;
        int q = 0;
        for(int i=nums.length-1; i>=1; i--) {     //eg. 7836421  p,q point to integer:  p -> 3, q -> 4
            if(nums[i-1]>=nums[i]) continue;
            p = i-1;
            break;
        }
        if(p==-1) {       //no next greater permutation
            for(int i=0; i<nums.length/2; i++) {
                swap(nums, i, nums.length-1-i);
            }
            return;
        }
        
        for(int i=nums.length-1; i>p; i--) {
            if(nums[i]<=nums[p]) continue;
            q = i;
            break;
        }
        swap(nums, p, q);
        
        for(int i=0; i<(nums.length-p-1)/2; i++) {
            swap(nums, p+1+i, nums.length-1-i);
        }
    }
    
    public void swap(int nums[], int m, int n) {
        int temp = nums[m];
        nums[m] = nums[n];
        nums[n] = temp;
    }
    
}