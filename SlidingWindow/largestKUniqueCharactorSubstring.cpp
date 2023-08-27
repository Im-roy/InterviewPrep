// URL: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
class Solution{
  public:
  
    int getUniqueChars(int f[]) {
        int cnt = 0;
        for(int i=0; i<26; i++) {
            if(f[i] > 0)
                cnt += 1;
        }
        return cnt;
    }
  
    int longestKSubstr(string s, int k) {
        int low = -1, high = 0, ans = -1;
        int sz = s.length(), f[26] = {0};
        
        while(high < sz) {
            f[s[high] - 'a'] += 1;
            
            while(getUniqueChars(f) > k) {
                low += 1;
                f[s[low] - 'a'] -= 1;
            }
            if(getUniqueChars(f) == k)
                ans = max(ans, high - low);
            high += 1;
        }
        return ans;
    }
};