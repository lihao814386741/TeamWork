//solution 1: hashmap
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> lists = new LinkedList<List<Integer>>();
        for(int i=0; i<nums.length-2; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;    //handle duplicate
            int target = -1*nums[i];
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            for(int j=i+1; j<nums.length; j++) {
                if(map.containsKey(nums[j])) {
                    if(map.get(nums[j])>0) continue;      //use hashmap to handle duplicate
                    List<Integer> list = new LinkedList<Integer>();
                    list.add(nums[i]);
                    list.add(target-nums[j]);
                    list.add(nums[j]);
                    lists.add(list);
                    map.put(nums[j], map.get(nums[j])+1);
                } else {
                    map.put(target-nums[j], 0);
                }
            }
        }
        return lists;
    }
    
}


//solution 2: two pointers
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> lists = new LinkedList<List<Integer>>();
        for(int i=0; i<nums.length-2; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;    //handle duplicate
            int j = i+1;
            int k = nums.length-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0) {
                    List<Integer> list = new LinkedList<Integer>();
                    list.add(nums[i]);
                    list.add(nums[j]);
                    list.add(nums[k]);
                    lists.add(list);
                    j++;
                    k--;
                    while(j<nums.length-1 && nums[j]==nums[j-1]) j++;   //handle duplicate
                    while(k>j && nums[k]==nums[k+1]) k--;
                } else if(sum<0){
                    j++;
                } else {
                    k--;
                }
            }
        }
        return lists;
    }
}