/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/**
 * 1. lessThan cannot be non-static member function;
 */
 
bool lessThan(const Interval &interval1, const Interval &interval2) {
    return interval1.start < interval2.start;
}
    
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // Special case.
        if (intervals.empty()) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), lessThan);
        
        int valid = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals.at(i).start <= intervals.at(valid).end) {
                intervals.at(valid).end = max(intervals.at(valid).end, intervals.at(i).end);
            } else {
                ++valid;
                intervals.at(valid).start = intervals.at(i).start;
                intervals.at(valid).end = intervals.at(i).end;
            }
        }
        
        intervals.resize(valid + 1);
        return intervals;
    }

};
