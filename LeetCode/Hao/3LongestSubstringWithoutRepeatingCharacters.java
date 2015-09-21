public class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> hashMap = new HashMap<Character, Integer>();
        
        int slow, fast;
        slow = fast = 0;
        int maxLength = 0;
        
        while (fast < s.length()) {
            char c = s.charAt(fast);
            
            if (hashMap.containsKey(c) == false) {
                hashMap.put(c, fast);
            } else {
                slow = Math.max(slow, hashMap.get(c) + 1);
                hashMap.put(c, fast);
            }
            
            maxLength = Math.max(maxLength, fast - slow + 1);
            
            fast ++;
        }
        
        return maxLength;
    }
}
