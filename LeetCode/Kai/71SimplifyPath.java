public class Solution {
    public String simplifyPath(String path) {
        LinkedList<String> ls = new LinkedList<String>();
        String[] folderName = path.split("\\/+");
        
        for(int i=0; i<folderName.length; i++) {
            if(folderName[i].equals(".") || folderName[i].equals("")) continue;
            else if(folderName[i].equals("..")) {
                if(ls.size()!=0) ls.removeLast();
            } else {
                ls.add(folderName[i]);
            }
        }
        
        if(ls.size()==0) return "/";
        else {
            StringBuilder sb = new StringBuilder();
            for(int i=0; i<ls.size(); i++) sb.append("/"+ls.get(i));
            return sb.toString();
        }
        
    }
    
}