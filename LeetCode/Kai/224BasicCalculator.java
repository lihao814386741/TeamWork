public class Solution {
    public int calculate(String s) {
        Stack<String> stack = new Stack<String>();
        s = s.trim();
        for(int i=0; i<s.length(); i++) {
            String str = s.substring(i, i+1);
            if(str.equals(" ")) continue;
            if(str.equals(")")) {
                int result = 0;
                while(!stack.isEmpty()) {
                    int digit = Integer.parseInt(stack.pop());
                    if(stack.isEmpty()) {
                        result += digit;
                        break;
                    }
                    String popStr = stack.pop();
                    if(popStr.equals("(")) {
                        result += digit;
                        break;
                    }
                    result = operate(result, digit, popStr);
                }
                stack.push(String.valueOf(result));
            } else {
                int count = 0;
                while(i+count<s.length()-1
                      && str.matches("[0-9]")
                      && s.substring(i+1+count, i+2+count).matches("[0-9]")) {
                    count++;
                }
                str = s.substring(i, i+1+count);   //alternative approach: use sb.append(char) instead of substring(start, end)
                stack.push(str);
                i += count;
            }
            
        }
        int sum = 0;
        while(!stack.isEmpty()) {
            int digit = Integer.parseInt(stack.pop());
            if(stack.isEmpty()) {
                sum += digit;
                break;
            }
            String operate = stack.pop();
            sum = operate(sum, digit, operate);
        }
        return sum;
    }
    
    public int operate(int num1, int num2, String operate) {
        int result = 0;
        switch(operate) {
            case "+":
                result = num1 + num2;
                break;
            case "-":
                result = num1 - num2;
                break;
        }
        return result;
    }
}