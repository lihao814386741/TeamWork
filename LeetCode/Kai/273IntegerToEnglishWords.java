public class Solution {
    public String numberToWords(int num) {
        if(num == 0) return "Zero";   //corner case
        
        StringBuilder sb = new StringBuilder();
        //Group num by 3 digits and pass it to helper, like 2,147,483,647
        if(num>=1000000000) {
            sb.append(helper(num/1000000000));
            sb.append(" Billion");
            num %= 1000000000;
            if(num!=0) sb.append(" ");   //remember when to append " ". Really pain in the ass
        }
        if(num>=1000000) {
            sb.append(helper(num/1000000));
            sb.append(" Million");
            num %= 1000000;
            if(num!=0) sb.append(" ");
        }
        if(num>=1000) {
            sb.append(helper(num/1000));
            sb.append(" Thousand");
            num %= 1000;
            if(num!=0) sb.append(" ");
        }
        sb.append(helper(num));
        return sb.toString();
    }
    
    public String helper(int n) {
        
        int[] nums = {90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        String[] words = {"Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One"};
        
        StringBuilder sb = new StringBuilder();
        if(n>=100) {
            int hundredDigit = n/100;
            for(int i=0; i<nums.length; i++) {
                while(hundredDigit>=nums[i]) {
                    sb.append(words[i]);
                    sb.append(" Hundred");
                    hundredDigit -= nums[i];
                }
            }
            n %= 100;
            if(n!=0) sb.append(" ");
        }
        
        for(int i=0; i<nums.length; i++) {
            while(n>=nums[i]) {
                sb.append(words[i]);
                n -= nums[i];
                if(n!=0) sb.append(" ");
            }
        }
        return sb.toString();
    }
    
}