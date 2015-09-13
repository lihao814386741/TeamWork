public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        StringBuilder sb = new StringBuilder();
        
        long num = Math.abs((long)numerator);   //Use long instead of int to avoid overflow
        long deno = Math.abs((long)denominator);  // eg. numerator = -1, denominator = -2147483648
        String sign = (numerator>0 == denominator>0) || numerator==0 ? "" : "-";
        sb.append(sign);
        
        sb.append(num/deno);
        long remainder = num%deno;
        if(remainder==0) return sb.toString();
        
        sb.append(".");
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        while(!map.containsKey(remainder)) {
            map.put(remainder, sb.length());
            sb.append(remainder*10/deno);
            remainder = remainder*10%deno;
        }
        int index = map.get(remainder);
        sb.insert(index, "(");
        sb.append(")");
        
        return sb.toString().replace("(0)", "");
    }
    
}