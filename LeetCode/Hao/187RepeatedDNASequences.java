public class Solution {
    private int getIndex(char c) {
        if (c == 'A') {
            return 0;
        } else if (c == 'C') {
            return 1;
        } else if (c == 'G') {
            return 2;
        } else  {
            return 3;
        }
    }
    
    public List<String> findRepeatedDnaSequences(String s) {
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
        List<String> ans = new ArrayList<String>();
        int index = 0;
        int m = 1048576;
        
        if (s.length() < 10) {
            return ans;
        }
        
        for (int i = 0; i < 10; i ++) {
            index *= 4;
            index += getIndex(s.charAt(i));
        }
        hashMap.put(index, 1);
        
        for (int i = 10; i < s.length(); i ++) {
            index *= 4;
            index %= m;
            index += getIndex(s.charAt(i));
            
            if (hashMap.containsKey(index) == true) {
                int freq = hashMap.get(index);
                if (freq == 1) {
                    //store to answer.
                    ans.add(s.substring(i - 9, i + 1));
                }
                hashMap.put(index, freq + 1);
            } else {
                hashMap.put(index, 1);
            }
        }
        
        return ans;
    }
}
