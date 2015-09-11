//
/*
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times. 规定数组中必然存在一个出现次数大于n/2的元素
 You may assume that the array is non-empty and the majority element always exist in the array.
//*/
#include <iostream>
#include <sstream>
#include <vector>
using namespace::std;
class Solution {
public:
// Moore Voting Algorithm
// Refer to:
// http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
    int majorityElement(vector<int> &num) {
        int majority;
        int count = 0;
        for (int i=0; i<int(num.size()); i++) {
            if (count==0) {
                majority = num[i];
                count++;
            }
            else{
                majority == num[i] ? count++ : count--;
                if (count>=num.size()/2+1) {
                    return majority;
                }
            }
        }
        return majority;
    }
    
    vector<int> &split(const string &s, char delim, vector<int> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(atoi(item.c_str()));
        }
        return elems;
    }
    
    vector<int> split(const string &s, char delim) {
        vector<int> elems;
        split(s, delim, elems);
        return elems;
    }
};
int main() {
    Solution sol;
    string array = "1,3,3,4,3,4,3,3,2,3,1";
    cout << "[" << array << "]" <<endl;
    vector<int> num = sol.split(array, ',');
    cout << sol.majorityElement(num) << endl;
    return 0;
}
