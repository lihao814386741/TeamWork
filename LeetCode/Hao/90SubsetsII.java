public class Solution {
    private List<List<Integer>> sets;
    
    private void searchSets(int[] nums, int pos, int size, LinkedList<Integer> set) {
        if (size == 0) {
            sets.add(new LinkedList<Integer> (set));
            return;
        }
        int i = pos;
        
        while (i < nums.length) {
            
            set.add(nums[i]);
            searchSets(nums, i + 1, size - 1, set);
            set.removeLast();
            int last = nums[i];
            
            for (; i < nums.length ; i++)
            {
                if (nums[i] != last)
                {
                    break;
                }
            }
        }
    } 
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        sets = new ArrayList<List<Integer>> ();
        LinkedList<Integer> set = new LinkedList<Integer>();
    
        Arrays.sort(nums);
    
        for (int i = 0; i <= nums.length; i ++) {
            searchSets(nums, 0, i, set);
        }    
        
        return sets;
    }
}

public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> sets = new ArrayList<List<Integer>> ();
        List<Integer> set = new ArrayList<Integer>();
        sets.add(set);
        Arrays.sort(nums);
        
        int previousSize = 0;
        
        
        for (int i = 0; i < nums.length; i ++) {
            int j;
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                j = previousSize;
            } else {
                j = 0;
            }
            
            int currentSize;
            currentSize = previousSize = sets.size();
            
            for (; j < currentSize; j ++) {
                set = new ArrayList<Integer> (sets.get(j));
                set.add(nums[i]);
                sets.add(set);
            }
        }
        
        
        return sets;
    }
}
