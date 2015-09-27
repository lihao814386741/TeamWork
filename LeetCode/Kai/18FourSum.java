//two pointers
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> lists = new LinkedList<List<Integer>>();
        for(int i=0; i<nums.length-3; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;   //handle duplicate
            for(int j=i+1; j<nums.length-2; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;   //handle duplicate
                int p1 = j+1;
                int p2 = nums.length-1;
                while(p1<p2) {
                    int sum = nums[i]+nums[j]+nums[p1]+nums[p2];
                    if(sum == target) {
                        List<Integer> list = new LinkedList<Integer>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[p1]);
                        list.add(nums[p2]);
                        lists.add(list);
                        
                        p1++;
                        p2--;
                        while(p1<p2 && nums[p1]==nums[p1-1]) p1++;   //handle duplicate
                        while(p2>p1 && nums[p2]==nums[p2+1]) p2--;
                        
                    } else if(sum<target) {
                        p1++;
                    } else if(sum>target) {
                        p2--;
                    }
                }
            }
        }
        return lists;
    }
    
}