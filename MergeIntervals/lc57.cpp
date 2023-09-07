// URL: https://leetcode.com/problems/insert-interval/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        int i = 0;
        while(i < intervals.size() and intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i += 1;
        }
        
        while(i < intervals.size() and intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i += 1;
        }
        result.push_back(newInterval);
        
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};