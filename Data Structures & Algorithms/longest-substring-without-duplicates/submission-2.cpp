class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        vector<int> charFreq(256, 0);
        int n = s.size();
        int ans = 0;
        while (j<n) {
            // expand right
            while (j < n && charFreq[s[j]] == 0) {
                charFreq[s[j]] = 1;
                j++;
            }
            ans = max(ans, j-i);
            // shrink from left
            while (i < j && charFreq[s[j]] != 0) {
                charFreq[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};
