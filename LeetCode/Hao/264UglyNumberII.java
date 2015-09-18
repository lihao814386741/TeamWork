public class Solution {
    public int nthUglyNumber(int n) {
        int u2 = 0;
        int u3 = 0;
        int u5 = 0; 
        int k = 1;
        List<Integer> uglyList = new ArrayList<Integer>();
        uglyList.add(1);
                
        while (k <= n) {
            int l2 = uglyList.get(u2) * 2;
            int l3 = uglyList.get(u3) * 3;
            int l5 = uglyList.get(u5) * 5;
            
            int smallest = Math.min(l2, Math.min(l3, l5));
            
            if (smallest == l2) {
                u2 ++;
            } 
            if (smallest == l3) {
                u3 ++;
            } 
            if (smallest == l5) {
                u5 ++;
            }
            uglyList.add(smallest);
            
            k ++; 
        }
        
        return uglyList.get(n - 1);
    }
}
