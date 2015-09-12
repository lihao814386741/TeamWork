public class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int[] result = new int[2];
        
        for(int i=0; i<nums.length;i++) {
            if(map.containsKey(nums[i])) {
                result[0] = map.get(nums[i])+1;
                result[1] = i+1;
                break;
            } else {
                map.put(target-nums[i], i);
            }
        }
        return result;
    }
    
}