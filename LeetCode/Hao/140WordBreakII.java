public class Solution {
    private List<String> ans;
    private void dfs(int pos, int length, boolean[] isInDict, String curString, List<List<String>> lOfL)
    {
        if (pos == -1)
        {
            ans.add(curString);
            return ;
        }
        
        if (isInDict[pos] != true)
        {
            return ;
        }
        
        for (String s : lOfL.get(pos))
        {
            if (curString.equals(""))
            {
                String tmp = new String(s);
                dfs(pos - s.length(), length, isInDict, tmp, lOfL);                
            }
            else
            {
                String tmp = new String(s + " " + curString);
                dfs(pos - s.length(), length, isInDict, tmp, lOfL);
            }
        }
        
        
        return ;
    }
    
    
    public List<String> wordBreak(String s, Set<String> dict) {
        int length = s.length();
        List<List<String>> lOfL = new ArrayList<List<String>>();
        ans = new ArrayList<String>();
        boolean[] isInDict = new boolean[length];
        
        
        for (int i = 0; i < length; i ++)
        {
            List<String> l = new ArrayList<String>();
            
            for (String word : dict)
            {
                int wordl = word.length();
                
                if (i >= wordl - 1 && s.substring(i - wordl + 1, i + 1).equals(word))
                {
                    if (i == wordl - 1)
                    {
                        isInDict[i] = true;
                        l.add(word);
                    }
                    
                    else if (isInDict[i - wordl] == true) 
                    {
                        isInDict[i] = true;
                        l.add(word);
                    }
                }
            }
            
            lOfL.add(l);
        }
        
        if (isInDict[length - 1] == false)
        {
            return new ArrayList<String>();
            
        }
        
        dfs(length - 1, length - 1, isInDict, "", lOfL);
        
        
        return ans;
    }
}
