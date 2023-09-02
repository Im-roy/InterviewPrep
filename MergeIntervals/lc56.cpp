// URL: https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int low, high;
        vector<vector<int>> result;
        
        for(int i=0; i<intervals.size(); i++) {
            if(i == 0) {
                low = intervals[i][0];
                high = intervals[i][1];
                continue;
            }
            if(intervals[i][0] <= high) {
                high = max(high, intervals[i][1]);
            } else {
                result.push_back({low, high});
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }
        result.push_back({low, high});
        return result;
    }
};