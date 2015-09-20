class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int last = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int temp;
            switch (s.at(i)) {
                case 'I': temp = 1; break;
                case 'V': temp = 5; break;
                case 'X': temp = 10; break;
                case 'L': temp = 50; break;
                case 'C': temp = 100; break;
                case 'D': temp = 500; break;
                case 'M': temp = 1000; break;
            }
            if (last < temp) {
                result += temp - 2 * last;
            } else {
                result += temp;
            }
            last = temp;
        }
        return result;
    }
};