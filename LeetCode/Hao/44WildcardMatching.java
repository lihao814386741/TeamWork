public class Solution {
    private String deleteDuplicateStar(String s) {
        if (s.length() <= 1) {
            return s;
        }
        StringBuilder sb = new StringBuilder();
        char last = s.charAt(0);
        sb.append(last);
        
        for (int i = 1; i < s.length(); i ++) {
            char c = s.charAt(i);
            
            if (c != last || c != '*'){
                sb.append(c);
            }
            
            last = c;
        }
        
        return sb.toString();
    }
    
    public boolean isMatch(String s, String p) {
        p = deleteDuplicateStar(p);

        boolean[][] f = new boolean[p.length() + 1][s.length() + 1];
        
        
        if (p.length() <= 0) {
            return s.equals(p);
        } else if (s.length() <= 0) {
            return p.equals("*");
        }
        
        char firstc = p.charAt(0);
        if (firstc == '*') {
            for (int i = 0; i < s.length(); i ++) {
                f[0][i] = true;
            }
            if (p.length() > 1 && (p.charAt(1) == '?' || p.charAt(1) == s.charAt(0))) {
                f[1][0] = true;
            }
        } else if (firstc == '?') {
            f[0][0] = true;
        } else if (firstc == s.charAt(0)) {
            f[0][0] = true;
        }
        
        
        
        for (int i = 1; i < p.length(); i ++) {
            char cp = p.charAt(i);
            if (cp == '*') {
                boolean setone = false;
                for (int k = 0; k < s.length(); k ++) {
                    if (setone == true) {
                        f[i][k] = true;
                    } else if (f[i - 1][k] == true) {
                        setone = true;
                        f[i][k] = true;
                    }
                }
            }
            
            for (int j = 1; j < s.length(); j ++) {
                char cs = s.charAt(j);
                
                if (cp == '?' || cp == cs) {
                    f[i][j] = f[i - 1][j - 1];
                } 
                
            }
        }
        
        return f[p.length() - 1][s.length() - 1];
    }
}
