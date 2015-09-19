class Solution {
public:
    string getPermutation(int n, int k) {
        // Corner case.
        if (n == 1) {
            return "1";
        }
        // Calculate (n - 1)! (n - 1 factorial)
        int fac = 1;
        vector<char> vtr(n);
        for (int i = 0; i < n; ++i) {
            fac *= (i + 1);
            vtr.at(i) = i + '1';
        }
        --k;
        
        string result = "";
        for (int i = n; i >= 1; --i) { // I need to choose n number.
            fac /= i;
            int idx = k / fac;
            result += vtr.at(idx);
            vtr.erase(vtr.begin() + idx);
            k %= fac;
        }
        return result;
    }
};
