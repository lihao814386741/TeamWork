public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<Integer>();
        }
        int first = nums[0];
        int second = nums[nums.length / 3];
        int third = nums[nums.length * 2 / 3];
        int forth = nums[nums.length - 1];
        int[] freq = new int[]{0, 0, 0, 0, 0};
        
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] == first){
                freq[1] ++;
            } else if (nums[i] == second) {
                freq[2] ++;
            } else if (nums[i] == third) {
                freq[3] ++;
            } else if (nums[i] == forth) {
                freq[4] ++;
            }
        }
        List<Integer> list = new ArrayList<Integer>();
        int maxFreq = nums.length / 3;
        if (freq[1] > maxFreq) {
            list.add(first);
        } if (freq[2] > maxFreq && first != second) {
            list.add(second);
        } if (freq[3] >maxFreq && third != second) {
            list.add(third);        
        } if (freq[4] > maxFreq && forth != third) {
            list.add(forth);
        }
        
        return list;
    }
}
