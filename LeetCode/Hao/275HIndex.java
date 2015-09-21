public class Solution {
    public int hIndex(int[] citations) {
        int max = 0;
        for (int i = citations.length - 1; i >= 0; i --) {
            int hIndex = citations.length - i;
            
            if (citations[i] >= hIndex) {
                max = hIndex;
            }
        }
        return max;
    }
} 
