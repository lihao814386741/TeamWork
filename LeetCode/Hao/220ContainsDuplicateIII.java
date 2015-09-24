public class Solution {
    public class Info{
        int value;
        int position; 
        
        public Info(int value, int position) {
            this.value = value;
            this.position = position; 
        }
    }
    
    private boolean isValid(Map<Long, Info> hmap, long key, int pos, int k, int t, int realValue) {
        if (hmap.containsKey(key) == true) {
            Info info = hmap.get(key);
            
            if ( pos - info.position <= k && Math.abs(info.value - realValue) <= t) {
                return true;
            }
        }
        
        return false;
        
    }
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums.length <= 0 || k <= 0 || t < 0) {
            return false;
        }
        
        Map<Long, Info> hmap = new HashMap<Long, Info>();
        
        for (int i = 0; i < nums.length; i ++) {
            long temp;
            if (t == 0) {
                temp = (long) nums[i] + Integer.MAX_VALUE; 
                if (isValid(hmap, temp, i, k, t, nums[i]) == true) {
                    return true;
                }
            } else {
                temp = ((long) nums[i] + Integer.MAX_VALUE) / t;
                if (isValid(hmap, temp, i, k, t, nums[i]) == true) {
                    return true;
                } else if (isValid(hmap, temp + 1, i, k, t, nums[i]) == true) {
                    return true;
                } else if (isValid(hmap, temp - 1, i, k, t, nums[i]) == true) {
                    return true;
                }
            }
            Info info = new Info(nums[i], i);
            
            hmap.put(temp, info);
            
        }
        
        return false;
    
    }
}
