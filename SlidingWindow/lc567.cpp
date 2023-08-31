// URL: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    
    bool isEqual(int f1[], int f2[]) {
        for(int i=0; i<26; i++) {
            if(f1[i] != f2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int f1[26] = {0}, f2[26] = {0};
        for(auto x: s1) f1[x - 'a'] += 1;
        
        int low = 0;
        for(int i=0; s2[i]; i++) {
            f2[s2[i] - 'a'] += 1;
            if(i >= s1.length() - 1) {
                if(isEqual(f1, f2)) {
                    return true;
                }
                f2[s2[low++] - 'a'] -= 1;
            }
        }
        return false;
    }
};