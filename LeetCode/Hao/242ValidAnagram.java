public class Solution {
    public boolean isAnagram(String s, String t) {
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();
        
        Arrays.sort(sc);
        Arrays.sort(tc);
        String a =  new String(sc);
        String b = new String(tc);
        
        return a.equals(b);
    }
}
