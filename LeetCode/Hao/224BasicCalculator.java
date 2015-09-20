public class Solution {
    private boolean isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    private int toInteger(char c){
        return c - '0';
    }
    
    private List<String> preCalculate(String s) {
        int i = 0;
        List<String> result = new ArrayList<String>();
        
        while (i < s.length()) {
            char c = s.charAt(i);
            
            if (isNumber(c) == true) {
                StringBuilder sb = new StringBuilder();
                while (i < s.length() && isNumber(s.charAt(i))) {
                    sb.append(s.charAt(i));
                    i ++;
                }
                result.add(sb.toString());
            } else if (c != ' ') {
                result.add(Character.toString(c));
                i++;
            } else {
            	i ++;
            }
        }
        
        return result;
    }
    
    private List<String> toReverseNotion(List<String> list) {
        List<String> reverseNotion = new ArrayList<String> ();
        Stack<String> tmpStack = new Stack<String> ();
        
        for (String s : list) {
            if (s.equals("(") == true) {
                tmpStack.add(s);
            } else if (s.equals(")") == true) {
                while (tmpStack.peek().equals("(") == false) {
                    reverseNotion.add(tmpStack.pop());
                }
                tmpStack.pop();
            } else if (s.equals("+") == true || s.equals("-") == true) {
            	while (tmpStack.size() != 0 && this.getValue(tmpStack.peek()) >= this.getValue(s)){
            		reverseNotion.add(tmpStack.pop());
            	}
                tmpStack.push(s);
            } else {
                reverseNotion.add(s);
            }
        }
        
        while (tmpStack.empty() == false) {
            reverseNotion.add(tmpStack.pop());
        }
        
        return reverseNotion;
    }
    
    private int calculate(List<String> reverseNotion) {
        Stack<Integer> numberStack = new Stack<Integer>();
        
        for (String s: reverseNotion) {
            
            if (s.equals("+") == true) {
                int op1 = numberStack.pop();
                int op2 = numberStack.pop();
                numberStack.push(op1 + op2);
            } else if (s.equals("-") == true) {
                int op2 = numberStack.pop();
                int op1 = numberStack.pop();
                numberStack.push(op1 - op2);
            } else {
                numberStack.push(Integer.parseInt(s));
            }
        }
        
        return numberStack.pop();
    }
    
    public static int getValue(String s) {  
        if (s.equals("+")) {  
            return 1;  
        } else if (s.equals("-")) {  
            return 1;  
        } else if (s.equals("*")) {  
            return 2;  
        } else if (s.equals("/")) {  
            return 2;  
        }  
        return 0;  
    } 
    
    
    
    public int calculate(String s){
        List<String> preCal = preCalculate(s);
        List<String> reverseNotion = toReverseNotion(preCal);
        return calculate(reverseNotion);
    }
}
