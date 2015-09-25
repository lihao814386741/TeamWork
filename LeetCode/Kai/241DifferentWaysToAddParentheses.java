public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> result = new LinkedList<Integer>();
        for(int i=0; i<input.length(); i++) {
            char c = input.charAt(i);
            if(c=='+' || c=='-' || c=='*') {
                String part1 = input.substring(0, i);
                String part2 = input.substring(i+1, input.length());
                List<Integer> res1 = diffWaysToCompute(part1);
                List<Integer> res2 = diffWaysToCompute(part2);
                for(int n1 : res1) {
                    for(int n2 : res2) {
                        int res = 0;
                        switch(c) {
                            case '+':
                                res = n1+n2;
                                break;
                            case '-':
                                res = n1-n2;
                                break;
                            case '*':
                                res = n1*n2;
                                break;
                        }
                        result.add(res);
                    }
                }
            }
        }
        if(result.size()==0) {
            result.add(Integer.parseInt(input));   //when input is a single num
        }
        return result;
    }
    
}