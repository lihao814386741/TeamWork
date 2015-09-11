public class Solution {
    public final static int RED = 0;
    public final static int WHITE = 1;
    public final static int BLUE = 2;
    
    private void swap (int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    public void sortColors(int[] nums) {
        int begin, end, p;
        begin = p = 0;
        end = nums.length - 1;
        
        while (p <= end) {
            if (nums[p] == RED) {
                swap(nums, p, begin);
                p ++;
                begin ++;
            } else if (nums[p] == WHITE) {
                p ++;
            } else {
                swap(nums, p, end);
                end --;
            }
        }
        
        
    }
}
