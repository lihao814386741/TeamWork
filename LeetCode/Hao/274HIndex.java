public class Solution {
    public int hIndex(int[] citations) {
        
        int[] freq = new int[citations.length + 1];
        
        for (int i = 0; i < citations.length; i ++) {
            if (citations[i] > citations.length) {
                freq[citations.length] ++;
            } else {
                freq[citations[i]] ++;
            }
        }
        int sum = 0;
        int i;
        
        for (i = citations.length; i >= 0; i --) {

            sum += freq[i];
            if (sum >= i){
                break;
            }
        }
        
        return i;
    }
}
