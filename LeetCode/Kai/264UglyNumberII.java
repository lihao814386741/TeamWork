//solution 1: Time Limit Exceeded
public class Solution {
    public int nthUglyNumber(int n) {
        int count = 0;
        int num = 0;
        while(count!=n) {
            num++;
            if(isUgly(num)) count++;
        }
        return num;
    }
    
    public boolean isUgly(int num) {
        if(num<=0) return false;
        while(num%2==0) num = num/2;
        while(num%3==0) num = num/3;
        while(num%5==0) num = num/5;
        return num==1;
    }
    
}


//solution 2
public class Solution {
    public int nthUglyNumber(int n) {
        int uglyNums[] = new int[n];
        uglyNums[0] = 1;
        int l1 = 2;
        int l2 = 3;
        int l3 = 5;
        int l1Index = 0;
        int l2Index = 0;
        int l3Index = 0;
        
        for(int i=1; i<n; i++) {
            int minNum = Math.min(Math.min(l1, l2), l3);
            uglyNums[i] = minNum;
            
            if(minNum == l1) {
                l1Index++;
                l1 = uglyNums[l1Index]*2;
            }
            if(minNum == l2) {
                l2Index++;
                l2 = uglyNums[l2Index]*3;
            }
            if(minNum == l3) {
                l3Index++;
                l3 = uglyNums[l3Index]*5;
            }
        }
        
        return uglyNums[n-1];
    }
    
    
}
