public class Solution {
    private List<List<Integer>> sets;
    
    private void searchSets(int[] nums, int pos, int size, LinkedList<Integer> set) {
        if (size == 0) {
            sets.add(new LinkedList<Integer>(set));
            return;
        }
        
        for (int i = pos; i < nums.length; i ++) {
            set.add (nums[i]);
            searchSets(nums, i + 1, size - 1, set);
            set.removeLast();
        }
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        sets = new ArrayList<List<Integer>>();
        LinkedList<Integer> set = new LinkedList<Integer>();
        
        Arrays.sort(nums);
        
        for (int i = 0; i <= nums.length; i ++) {
            set.clear();
            searchSets(nums, 0, i, set);
        }
        
        return sets;
    }
}

public class Solution {
    
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> set = new ArrayList<Integer>();
        
        List<List<Integer>> sets = new ArrayList<List<Integer>> ();
        sets.add(set);
        
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length; i ++) {
            int currentSize = sets.size();
            for (int j = 0; j < currentSize; j ++) {
                set = new ArrayList<Integer>(sets.get(j));
                set.add(nums[i]);
                sets.add(set);
            }
            
        }

        
        
        return sets;
    }
}
