//solution 1: two pass
public class Solution {
    public void sortColors(int[] nums) {
        int countOne = 0;
        int countTwo = 0;
        for(int i=0; i<nums.length; i++) {
            if(nums[i]==0) countOne++;
            if(nums[i]==1) countTwo++;
        }
        for(int i=0; i<countOne; i++) {
            nums[i] = 0;
        }
        for(int i=countOne; i<countOne+countTwo; i++) {
            nums[i] = 1;
        }
        for(int i=countOne+countTwo; i<nums.length; i++) {
            nums[i] = 2;
        }
    }
    
}

//solution 2: one pass
public class Solution {
    public void sortColors(int[] nums) {
        int p0 = 0;
        int p1 = 0;
        int p2 = nums.length-1;
        while(p1<=p2) {
            if(nums[p1]==0) {
                if(p0!=p1) swap(nums, p0, p1);
                p0++;
                p1++;
            } else if(nums[p1]==1) {
                p1++;
            } else {
                swap(nums, p1, p2);
                p2--;
            }
        }
    }
    
    public void swap(int[] nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
}