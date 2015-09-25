public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        char[] arr = s.toCharArray();
        for(char c : arr) {
            if(c=='(' || c=='{' || c=='[') {
                stack.push(c);
            } else if(c==')') {
                if(stack.isEmpty() || stack.pop()!='(') return false;
            } else if(c=='}') {
                if(stack.isEmpty() || stack.pop()!='{') return false;
            } else if(c==']') {
                if(stack.isEmpty() || stack.pop()!='[') return false;
            }
        }
        return stack.isEmpty();
    }
    
}