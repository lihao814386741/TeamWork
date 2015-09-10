public class Solution {
    public boolean search(int[] nums, int target) {
        for (Integer number: nums) {
            if (number == target) {
                return true;
            }
        }
        return false;
    }
}
