/**
 * Special thanks to:
 * Kai and http://www.geeksforgeeks.org/ugly-numbers/
 * 
 * Forget about the misunderstanding hint;
 * Focus on the process of generate ugly number;
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNum(n);
        uglyNum.at(0) = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        for (int i = 1; i < uglyNum.size(); ++i) {
            uglyNum.at(i) = min(uglyNum.at(idx2) * 2, min(uglyNum.at(idx3) * 3, uglyNum.at(idx5) * 5));
            if (uglyNum.at(i) == uglyNum.at(idx2) * 2) {
                ++idx2;
            }
            // This is not else if(); Because 6 is in idx2 and idx3
            if (uglyNum.at(i) == uglyNum.at(idx3) * 3) {
                ++idx3;
            }
            
            if (uglyNum.at(i) == uglyNum.at(idx5) * 5) {
                ++idx5;
            }
        }
        return uglyNum.at(n - 1);
    }
};
