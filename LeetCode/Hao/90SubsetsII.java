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
