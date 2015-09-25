//Enum all the previous results
class Solution {
public:
    int nthUglyNumber(int n) {
        int *result = new int[n + 1];
        result[0] = 0;
        result[1] = 1;
        int k = 1;
        while (k < n) {
            int l2 = 0, l3 = 0, l5 = 0;
            int i = 0;
            while (l2 <= result[k]) {
                l2 = result[++i] * 2;
            }
            i = 0;
            while (l3 <= result[k]) {
                l3 = result[++i] * 3;
            }
            i = 0;
            while (l5 <= result[k]) {
                l5 = result[++i] * 5;
            }
            result[++k] = min(l2, min(l3, l5)); 
        }
        return result[n];
    }
};

//Each ugly number actually will be used just three times at most.
class Solution {
public:
    int nthUglyNumber(int n) {
        int *result = new int[n + 1];
        result[0] = 0;
        result[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        int k = 1;
        while (k < n) {
            int l2 = result[p2] * 2;
            int l3 = result[p3] * 3;
            int l5 = result[p5] * 5;
            result[++k] = min(l2, min(l3, l5)); 
            if (result[k] == l2) {
                p2++;
            }
            if (result[k] == l3) {
                p3++;
            }
            if (result[k] == l5) {
                p5++;
            }
        }
        return result[n];
    }
};