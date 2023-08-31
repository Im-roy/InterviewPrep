// URL: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    
    int replacedChar(int f[]) {
        vector<int> arr;
        for(int i=0; i<26; i++) {
            if(f[i] > 0) 
                arr.push_back(f[i]);
        }
        
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for(int i=0; i<arr.size() - 1; i++) {
            cnt += arr[i];
        }
        return cnt;
    }
    int characterReplacement(string s, int k) {
        
        int low = -1, high = 0, ans = 0;
        int f[26] = {0};
        
        while(high < s.length()) {
            f[s[high] - 'A'] += 1;
            while(replacedChar(f) > k) {
                low += 1;
                f[s[low] - 'A'] -= 1;
            }
            ans = max(ans, high - low);
            high += 1;
        }
        return ans;
    }
};