public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[]{-1, -1};
        Map<Integer, Integer> m = new HashMap<Integer, Integer> ();
        
        for (int i = 0; i < nums.length; i ++) {
            int k = target - nums[i];
            
            if (m.containsKey(k) == true) {
                result[0] = m.get(k);
                result[1] = i + 1;
            } else {
                m.put(nums[i], i + 1);
            }
            
        }
        
        return result;

    }
}
