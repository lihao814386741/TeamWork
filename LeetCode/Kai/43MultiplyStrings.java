public class Solution {
    public String multiply(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int[] output = new int[len1+len2];     //result will be no more than len1+len2 digits
        for(int i=len1-1; i>=0; i--) {
            for(int j=len2-1; j>=0; j--) {
                int index = len1+len2-i-j-2;
                output[index] += (num1.charAt(i)-'0') * (num2.charAt(j)-'0');
                output[index+1] += output[index]/10;
                output[index] = output[index]%10;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i=output.length-1; i>0; i--) {
            if(sb.length()==0 && output[i]==0) continue;
            sb.append(output[i]);
        }
        sb.append(output[0]);
        return sb.toString();
    }
    
}