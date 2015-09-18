public class Solution {
    public boolean isUgly(int num) {
        int[] factor = new int[]{2, 3, 5};
        if (num == 0) {
            return false;
        }
        
        for (int i = 0; i < factor.length; i ++) {
            while (num % factor[i] == 0) {
               num /= factor[i];
            }
        }
        
        return num == 1;
    }
}
