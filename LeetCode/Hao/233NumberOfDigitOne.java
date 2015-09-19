public class Solution {
    public int countDigitOne(int n) {
        if (n <= 0)
        {
            return 0;
        }
        
        int nRightSide = 0;
        int nLeftSide;
        
        int temp = n;
        int sum = 0;
        int pos = 1;
        
        while (temp != 0)
        {
            int currentDigit = (temp % 10);
            nLeftSide = temp / 10;
            nRightSide = n % pos; 
            
            int major, minor;
            
            if (currentDigit > 1)
            {
                major = nLeftSide + 1;
            }
            else 
            {
                major = nLeftSide;
            }
            
            if (currentDigit == 1)
            {
                minor = nRightSide + 1;
            }
            else 
            {
                minor = 0;
            }
            
            sum += major * pos + minor;
            
            temp /= 10;
            pos *= 10;
        }
        return sum;
    }
}
