public class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        if(s.length() == 0) return "";
        String[] words = s.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(int i=words.length-1; i>=1; i--) {
            sb.append(words[i]);
            sb.append(" ");
        }
        sb.append(words[0]);
        
        return sb.toString();
    }
    
}