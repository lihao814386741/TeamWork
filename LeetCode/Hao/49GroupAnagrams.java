public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hashMap = new HashMap<String, List<String>>();
        
        Arrays.sort(strs);
        
        for (int i = 0; i < strs.length; i ++) {
            char[] c = strs[i].toCharArray();
            Arrays.sort(c);
            String tmp = new String(c);
            
            if (hashMap.containsKey(tmp) == true) {
                hashMap.get(tmp).add(strs[i]);
            } else {
                List<String> l = new ArrayList<String> ();
                l.add(strs[i]);
                hashMap.put(tmp, l);
            }
        }
        List<List<String>> result = new ArrayList<List<String>> ();
        
        for (Map.Entry<String, List<String>> entry: hashMap.entrySet()) {
            result.add(entry.getValue());
        }
        
        return result;
    }
}
