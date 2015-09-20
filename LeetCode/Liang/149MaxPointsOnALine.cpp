/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
/**
 * Special thanks to: 
 * https://leetcode.com/discuss/45105/16ms-28ms-c-solutions-with-explanations
 * 
 * The way to calculate modulo -7%3:
 * (-7/3) => -2
 * -2 * 3 => -6
 * so a%b => -1
 * 
 * Be careful:
 * Duplicates!
 * 
 * Question:
 * getGCD(2, -3) == -getGCD(-2, 3);
 **/
 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) {
            return points.size();
        }
        int maxNum = 1;
        map<pair<int, int>, int> hash; // Cannot use unordered_map. It don't define the hash function for pair<T, U>;
        for (int i = 0; i < (int)points.size() - 2; ++i) {
            hash.clear();
            int duplicates = 0;
            for (int j = i + 1; j < (int)points.size(); ++j) {
                int dx = points.at(j).x - points.at(i).x;
                int dy = points.at(j).y - points.at(i).y;
                if (dx == 0 && dy == 0) {
                    ++duplicates;
                    continue;
                }
                
                int gcd = getGCD(dx, dy);
                pair<int, int> slopePair(dx/gcd, dy/gcd);
                if (hash.find(slopePair) != hash.end()) {
                    ++hash[slopePair];
                } else {
                    hash[slopePair] = 2;
                }
            }
            maxNum = max(maxNum, duplicates + 1); // deal with case: [1, 1], [1, 1], [1, 1];
            for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
                maxNum = max(maxNum, itr->second + duplicates);
            }
        }
        return maxNum;
    }
    
private:
    int getGCD(int num1, int num2) {
        // if num1 or num2 is zero, it will return the non zero one.
        while (num2) {
            int tmp = num2;
            num2 = num1 % num2;
            num1 = tmp;
        }
        return num1;
    }
};
