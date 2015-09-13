public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s==null || s.isEmpty()) return 0;   //corner case
        
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int pos = 0;
        int maxLen = 1;
        int dupIndex = 0;
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(!map.containsKey(c)) {
                map.put(c, i);
            } else {
                dupIndex = map.get(c);
                map.put(c, i);
                if(dupIndex < pos) continue;
                maxLen = Math.max(maxLen, i-pos);
                pos = dupIndex+1;
            }
        }
        return Math.max(maxLen, s.length()-pos);
    }
    
}