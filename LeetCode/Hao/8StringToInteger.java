public class Solution {
    int[][] status = new int[][]{
        {1, 2, 3},
        {3, 2, 3}, 
        {3, 2, 3}, 
        {3, 3, 3}
    };
    
    private final static int SIGN = 0;
    private final static int DIGIT = 1;
    private final static int OTHER = 2;
    
    private boolean isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    
    private int toInteger(char c) {
        return c - '0';
    }
    
    public int myAtoi(String str) {
        long num; 
        long sign = 1;
        num = 0;
        
        int step = 0;
        str = str.trim();
        
        for (int i = 0; i < str.length(); i ++) {
            char c = str.charAt(i);
            int letter = 2; 
            
            if (c == '+' || c == '-') {
                letter = SIGN;
                sign = (c == '-') ? -1 : 1;
            } else if (isNumber(c) == true) {
                letter = DIGIT;
                if (step != 3) {
                    if ((sign == 1 && num > Integer.MAX_VALUE) || 
                        (sign == -1 && -num < Integer.MIN_VALUE)){
                        break;    
                    } 
                    num *= 10;
                    num += toInteger(c);
                }
            } else {
                letter = OTHER;
            }
            
            step = status[step][letter];
        }
        
        num = num * sign;
        
        if (num > (long)Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        } else if (num < (long)Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }
        
        return (int)num;
        
        
    }
}
