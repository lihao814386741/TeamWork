public class Solution {
    public int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int left = 0;
        int right = x/2+1;   //sqrt(x) is smaller than x/2+1
        while(left<=right) {
            int mid = (left+right)/2;
            int temp = x/mid;
            if(temp==mid) return mid;
            else if(temp<mid) right = mid-1;
            else left = mid+1;
        }
        return right;   //notice the return value. It could also be (left-1)
    }
}