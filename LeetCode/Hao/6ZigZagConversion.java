public class Solution {
    public String convert(String s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        
        int cycle = 2 * numRows - 2;
        
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < numRows; i ++) {
            for (int j = i; j < s.length(); j += cycle) {
                char c = s.charAt(j);
                sb.append(c);
                int secondPos = j - i + cycle - i;
                
                if (i != 0 && i != numRows - 1 && secondPos < s.length()) {
                    sb.append(s.charAt(secondPos));
                }
            }
        }
        return sb.toString();
    }
}
