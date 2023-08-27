// URL: https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        
        for(int i=n-1; i>=0; i--) {
            if(i == n-1) {
                st.push({temp[i], i});
                continue;
            }
            while(st.size() and st.top().first <= temp[i]) {
                st.pop();
            }
            if(st.size() != 0) {
                res[i] = (st.top().second - i);
            }
            st.push({temp[i], i});
        }
        return res;
    }
};