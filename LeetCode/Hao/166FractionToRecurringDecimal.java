public class Solution {
    
    public String fractionToDecimal(int numerator, int denominator) {
        Map<Long, Integer> hashMap = new HashMap<Long, Integer>();
        List<Long> fracList = new ArrayList<Long>();
        
        long n = numerator;
        long d = denominator;
        int sign = 1;
        long integer = 0;
        
        if (n < 0) {
            n = -n;
            sign *= -1;
        }
        
        if (d < 0) {
            d = -d;
            sign *= -1;
        }
        
        if (n > d) {
            integer = n / d;
            n %= d;
        }
    
        int i = 0;
        
        while (n != 0) {
            if (hashMap.containsKey(n) == true) {
                break;
            } else {
                hashMap.put(n, i);
            }
            
            n *= 10;
            fracList.add(n / d);
            n %= d;
            i++;
        }
        
        String s = sign == 1? "" : "-";

        if (fracList.size() == 0) {
            if (integer == 0) {
                return "0";
            } 
            return s + Long.toString(integer);
        } else if (n == 0) {
            StringBuilder sb = new StringBuilder();
            sb.append(Long.toString(integer));
            sb.append(".");
            for (Long data : fracList) {
                sb.append(Long.toString(data));
            }
            
            return s + sb.toString();
        } else {
            StringBuilder sb = new StringBuilder();
            sb.append(Long.toString(integer));
            sb.append(".");
            int leftpar = hashMap.get(n);
            
            for (int j = 0; j < fracList.size(); j ++) {
                if (j == leftpar) {
                    sb.append('(');
                }
                sb.append(Long.toString(fracList.get(j)));            
            }
            sb.append(')');
        
            return s + sb.toString();
        }
        
    }
}
