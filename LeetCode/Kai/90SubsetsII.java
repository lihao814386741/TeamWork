public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> lists = new LinkedList<List<Integer>>();
        subsetsDFS(lists, new LinkedList<Integer>(), nums, 0);
        return lists;
    }
    
    public void subsetsDFS(List<List<Integer>> lists, List<Integer> list, int[] nums, int index) {
        lists.add(list);
        for(int i=index; i<nums.length; i++) {
            if(i>index && nums[i]==nums[i-1]) continue;   //handle duplicates
            List<Integer> newList = new LinkedList<Integer>(list);
            newList.add(nums[i]);
            subsetsDFS(lists, newList, nums, i+1);
        }
    }
    
}