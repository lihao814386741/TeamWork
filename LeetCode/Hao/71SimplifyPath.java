public class Solution {
    public String simplifyPath(String path) {
        String[] list = path.split("/");
        Stack<String> stack = new Stack<String>();
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < list.length; i ++) {
            if (list[i].equals("..")){
                if (stack.empty() == false) {
                    stack.pop();
                }
            } else if (list[i].equals(".") == true) {
                continue;
            } else if (list[i].trim().equals("") == false) {
                stack.push(list[i]);
            }
        }
        
        if (stack.empty() == false) {
            sb.append(stack.pop());
        }

        while (stack.empty() == false) {
            String tmp = stack.pop();
            sb.insert(0, tmp + "/");            
        }
        sb.insert(0, "/");
        
        return sb.toString();
    }
}
