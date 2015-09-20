class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            nums.push_back(i);
        }
        k--;
        string result = "";
        for (int i = n; i > 1; i--) {
            factorial /= i;
            int pos = k / factorial;
            k = k % factorial;
            result += to_string(nums.at(pos));
            nums.erase(nums.begin() + pos);
        }
        result += to_string(nums.at(0));
        return result;
    }
};