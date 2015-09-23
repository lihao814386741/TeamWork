public class Solution {
    private boolean isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    
    private Integer count(Integer a, Integer b, char c) {
        if (c == '+') {
            return a + b;
        } else if (c == '-') {
            return a - b;
        } else {
            return a * b;
        }
        
    }
    List<Integer> getSet(List<Integer> l1, List<Integer> l2, char c) {
        List<Integer> l = new LinkedList<Integer> ();
        for (Integer key1: l1) {
            for (Integer key2: l2){
                l.add(count(key1, key2, c));
            }
        }
        return l;
    }
     
    private List<Integer> helper(String s) {
        List<Integer> list = new LinkedList<Integer>();
        if (s.contains("+") == false && s.contains("-") == false && s.contains("*") == false){
            list.add(Integer.parseInt(s));
            return list;
        }
        
        for (int i = 0; i < s.length(); i ++) {
            char c = s.charAt(i);
            
            if (isNumber(c) == false) {
                list.addAll(getSet(helper(s.substring(0, i)), helper(s.substring(i + 1, s.length())), c));                
            }
        }
        return list;
        
    } 
    
    public List<Integer> diffWaysToCompute(String input) {
        return helper(input);
    }
}
