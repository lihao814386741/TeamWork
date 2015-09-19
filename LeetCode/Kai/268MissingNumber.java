//solution 1
public class Solution {
    public int missingNumber(int[] nums) {
        int len = nums.length;
        int sum = len*(len+1)/2;
        for(int i=0; i<len; i++) sum -= nums[i];
        return sum;
    }
    
}

//solution 2: bit manipulation
public class Solution {
    public int missingNumber(int[] nums) {
        int base = 0;
        for(int i=0; i<nums.length; i++) {
            base = base ^ i ^ nums[i];   //a ^ b ^ b == a
        }
        return base^nums.length;
    }
}