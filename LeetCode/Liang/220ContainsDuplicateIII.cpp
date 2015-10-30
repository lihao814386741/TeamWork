/**
verse the vector and at the same time keep a window with size of k and the element in the window is ordered. I choose set as the data structure.
 * 2. Find the whether [[i] - t, [i] + t] is in the window and insert it in the window.
 **/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
         assert(t >= 0 || k >= 0);
         if (k == 0) {
             return false;
         }
         
         set<int> window; // The implementation of set might be red-black tree.
         
         for (int i = 0; i < nums.size(); ++i) {
             if (i > k) {
                //  auto itr = window.find(nums.at(i - k)); // Probably there are duplicates. // It may not needed because it will return when found duplicate.
                 window.erase(nums.at(i - k - 1)); // Erase will throw exception when itr is not in set. Not erase i - k;
             }
             
             multiset<int>::iterator itr = window.lower_bound(nums.at(i) - t); // Not lower_bound of nums.at(i);
             if (itr != window.end() && *itr - nums.at(i) <= t) {
                 return true;
             }
             window.insert(nums.at(i));
             
            //  windows.begin() may not have element, window.end() definitely don't have any element;
            //  if (*window.begin() > nums.at(i) + t || *window.end() < nums.at(i) - t) {
            //      window.insert(nums.at(i));
            //      continue;
            //  } else {
            //      return true;
            //  }
         }
         
         return false;
    }
};
