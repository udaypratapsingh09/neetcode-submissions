class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> occ(26, 0);
        for (char& c:s) {
            occ[c-'a']++;
        }
        for (char& c:t) {
            occ[c-'a']--;
        }
        for (int i=0;i<26;i++) {
            if (occ[i] != 0) return false;
        }
        return true;
    }
};
