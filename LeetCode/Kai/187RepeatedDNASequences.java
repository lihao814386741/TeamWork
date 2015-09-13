public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        List<String> list = new LinkedList<String>();
        
        for(int i=0; i<s.length()-9; i++) {
            String str = s.substring(i, i+10);
            if(map.containsKey(str)) {
                if(map.get(str) == 1) list.add(str);
                map.put(str, map.get(str)+1);
            } else {
                map.put(str, 1);
            }
        }
        return list;
    }
    
}