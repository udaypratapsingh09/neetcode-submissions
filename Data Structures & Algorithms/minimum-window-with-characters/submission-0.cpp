class Solution {
public:
    string minWindow(string s, string t) {
        int count = 0;
        int freqS[128] = {0};
        int freqT[128] = {0};
        int k = 0;
        for (char& c:t) {
            if (freqT[c] == 0) k++;
            freqT[c]++;
        }
        int l=0,r=0;
        int n = s.size();
        int minSize = 1e9;
        string ans;
        while (r <= n) {
            if (count < k) {
                freqS[s[r]]++;
                if (freqS[s[r]] == freqT[s[r]]) count++;
                r++;
            }
            else {
                freqS[s[l]]--;
                if (freqS[s[l]] < freqT[s[l]]) {
                    count--;
                    int sz = r-l;
                    if (sz < minSize) {
                        minSize = sz;
                        ans = s.substr(l, sz);
                    }
                }
                l++;
            }
        }
        return ans;
    }
};
