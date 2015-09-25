//solution 1:  Time Limit Exceeded.
//Last executed input: 0.00001, 2147483647
public class Solution {
    public double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            x = 1/x;
            n = -n;
        }
        if(n==1) return x;
        
        if(n%2==1) return myPow(x, n/2) * myPow(x, n/2+1);
        else return myPow(x, n/2) * myPow(x, n/2);
    }
    
}


//solution 2
public class Solution {
    public double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            x = 1/x;
            n = -n;
        }
        
        double tmp = myPow(x, n/2);
        if(n%2==0) return tmp * tmp;
        else return tmp * tmp * x;
    }
}