// URL: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    
    bool isEqual(int f1[], int f2[]) {
        for(int i=0; i<26; i++) {
            if(f1[i] != f2[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int f1[26] = {0}, f2[26] = {0}, low = 0;
        for(auto x: p) f1[x - 'a'] += 1;
        
        vector<int> result;
        for(int i=0; s[i]; i++) {
            f2[s[i] - 'a'] += 1;
            if(i >= p.length() - 1) {
                if(isEqual(f1, f2)) {
                    result.push_back(low);
                }
                f2[s[low] - 'a'] -= 1;
                low += 1;
            }
        }
        return result;
    }
};