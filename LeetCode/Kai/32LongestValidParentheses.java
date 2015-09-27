public class Solution {
    public int longestValidParentheses(String s) {
        Stack<int[]> stack = new Stack<int[]>();
        int result = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)=='(') {
                int[] a = {i, 0};     //int[first, second]   first: index;  second: 0 for '(', 1 for ')'
                stack.push(a);
            } else {
                if(stack.isEmpty() || stack.peek()[1]==1) {
                    int[] a = {i, 1};
                    stack.push(a);
                } else {
                    stack.pop();
                    int currLen = 0;
                    if(stack.isEmpty()) {
                        currLen = i+1;
                    } else {
                        currLen = i-stack.peek()[0];
                    }
                    result = Math.max(result, currLen);
                }
            }
        }
        
        return result;
    }
    
}