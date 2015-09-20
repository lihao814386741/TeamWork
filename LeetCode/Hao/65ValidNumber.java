public class Solution {
    int[][] automata = {
        {-1, 2, 1, 3, -1, 0},
        {-1, 2, -1, 3, -1, -1},
        {-1, 2, -1, 4, 5, -1}, 
        {-1, 4, -1, -1, -1, -1},
        {-1, 4, -1, -1, 5, -1},
        {-1, 7, 6, -1, -1, -1},
        {-1, 7, -1, -1, -1, -1},
        {-1, 7, -1, -1, -1, 8},
        {-1, -1, -1, -1, -1, 8}
    };
    public final static int INVALID = 0;
    public final static int DIGIT = 1;
    public final static int SIGN = 2;
    public final static int DOT = 3;
    public final static int SCIE = 4;
    public final static int SPACE = 5;
    
    private boolean isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    private boolean isSign(char c) {
        return c == '-' || c == '+';
    }
    private boolean isDot(char c) {
        return c == '.';
    }
    private boolean isSciE(char c) {
        return c == 'e' || c == 'E';
    }
    
    public boolean isNumber(String s) {
        int status = 0;
        s = s.trim();
        
        for (int i = 0; i < s.length(); i ++) {
            char c = s.charAt(i);
            int inputType = 0;
            
            if (isNumber(c) == true) {
                inputType = 1;
            } else if (isSign(c) == true) {
                inputType = 2;
            } else if (isDot(c) == true) {
                inputType = 3;
            } else if (isSciE(c) == true) {
                inputType = 4;
            } else if (c == ' '){
                inputType = 5;
            }
            
            
            status = automata[status][inputType];    
            
            if (status == -1) {
                return false;
            }
            
        }
        
        return status == 2 || status == 4 || status == 7 || status == 8;
    }
}
