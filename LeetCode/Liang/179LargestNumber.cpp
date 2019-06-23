struct largerThan {
    bool operator()(const int &a, const int &b) const {
        string aStr = to_string(a), bStr = to_string(b);
        return (aStr + bStr) > (bStr + aStr); // Tricky part; overload > instead of <
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), largerThan());
        if (nums.at(0) == 0) { // Corner case.
            return "0";
        }
        
        string result;
        for (int i = 0; i < nums.size(); ++i) {
            result += to_string(nums.at(i));
        }
        return result;
    }
};
