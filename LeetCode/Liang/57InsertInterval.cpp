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
 * See Binary search as lower bound or upper bound search helps a lot.
 **/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            return vector<Interval>(1, newInterval);
        }
        
        int lowBound = lowerBoundHelper(intervals, newInterval);
        int upperBound = upperBoundHelper(intervals, newInterval);
        
        vector<Interval> result(intervals.begin(), intervals.begin() + lowBound);
        cout << lowBound << ", " << upperBound;
        if (lowBound < upperBound) {
            // Need merge;
            newInterval.start = min(newInterval.start, intervals.at(lowBound).start);
            newInterval.end = max(newInterval.end, intervals.at(upperBound - 1).end);
        }
        
        result.push_back(newInterval);
        result.insert(result.end(), intervals.begin() + upperBound, intervals.end());
        return result;
    }
private:
    int lowerBoundHelper(vector<Interval> &intervals, Interval &newInterval) {
        assert(!intervals.empty());
        int begin = 0, end = intervals.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (newInterval.start <= intervals.at(mid).end) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        
        if (newInterval.start > intervals.at(begin).end) {
            return begin + 1;
        } else {
            return begin;
        }
    }
    
    int upperBoundHelper(vector<Interval> &intervals, Interval &newInterval) {
        assert(!intervals.empty());
        int begin = 0, end = intervals.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (newInterval.end < intervals.at(mid).start) { // It's not >
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        
        if (newInterval.end >= intervals.at(begin).start) {
            return begin + 1; 
        } else {
            return begin;
        }
    }
};
