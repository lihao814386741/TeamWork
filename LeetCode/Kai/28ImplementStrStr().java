public class Solution {
    public int strStr(String haystack, String needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        if(needleLen==0) return 0;
        if(needleLen>haystackLen) return -1;
        
        for(int i=0; i<haystackLen-needleLen+1; i++) {
            String part = haystack.substring(i, i+needleLen);
            //if(part.equals(needle)) return i;
            for(int j=0; j<needleLen; j++) {
                if(part.charAt(j)!=needle.charAt(j)) break;
                if(j==needleLen-1) return i;
            }
        }
        return -1;
    }
    
}