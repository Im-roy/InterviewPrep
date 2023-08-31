// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    
    bool isRepeating(map<char, int> mp) {
        for(auto x: mp) {
            if(x.second > 1)
                return true;
        }
        return false;
    }
    
    int lengthOfLongestSubstring(string s) {
        
        int low = -1, high = 0, ans = 0;
        map<char, int> mp;
        while(high < s.length()) {
            mp[s[high]] += 1;
            while(isRepeating(mp)) {
                low += 1;
                mp[s[low]] -= 1;
                if(mp[s[low]] == 0) {
                    mp.erase(s[low]);
                }
            }
            ans = max(ans, high - low);
            high += 1;
        }
        return ans;
    }
};