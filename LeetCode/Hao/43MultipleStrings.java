public class Solution {
    public String multiply(String num1, String num2) {
        List<Integer> ans = new ArrayList<Integer>();
        int index1 = num1.length();
        int index2 = num2.length();
        int carry = 0;
        int[] product = new int[num1.length() + num2.length()];
        for(int i = num1.length() - 1; i >= 0; i --) {
            for (int j = num2.length() - 1; j >= 0; j --) {
                int d1 = num1.charAt(i) - '0';
                int d2 = num2.charAt(j) - '0';
                product[i + j + 1] += d1 * d2;
            }
        }
        
        for (int i = product.length - 1; i >= 0; i --) {
            int tmp = (product[i] + carry) % 10;
            carry = (product[i] + carry) / 10;
            product[i] = tmp;
        }
        
        StringBuilder sb = new StringBuilder();
        
        int i = 0;
        
        while (i < product.length && product[i] == 0) {
            i ++;
        }
        for (;i < product.length; i ++){
            sb.append(product[i]);
        }
        
        return sb.length() != 0 ? sb.toString(): "0";
    }
}
