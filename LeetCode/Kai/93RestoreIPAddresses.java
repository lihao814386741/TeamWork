public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> list = new LinkedList<String>();
        dfs(list, "", s, 0);
        return list;
    }
    
    public void dfs(List<String> list, String result, String s, int n) {
        if(s.length()==0) return;
        if(n==3) {
            if(s.length()==1
               || (s.length()==2 && Integer.parseInt(s.substring(0, 2))>=10)
               || (s.length()==3 && Integer.parseInt(s.substring(0, 3))>=100 && Integer.parseInt(s.substring(0, 3))<=255)) {
                result += s;
                list.add(result);
            }
            return;
        }
        
        if(s.length()>=1) dfs(list, result+s.substring(0, 1)+".", s.substring(1), n+1);
        if(s.length()>=2 && Integer.parseInt(s.substring(0, 2))>=10) dfs(list, result+s.substring(0, 2)+".", s.substring(2), n+1);
        if(s.length()>=3
           && Integer.parseInt(s.substring(0, 3))>=100
           && Integer.parseInt(s.substring(0, 3))<=255) dfs(list, result+s.substring(0, 3)+".", s.substring(3), n+1);
        
    }
    
}