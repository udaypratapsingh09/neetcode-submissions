class Solution {
public:
    bool isAlphaNumeric(char c) {
        if (c >= '0' && c <= '9') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        int k = 'Z' - 'z';
        while (i<j) {
            if (!isAlphaNumeric(s[i])) {i++;continue;}
            else if (!isAlphaNumeric(s[j])) {j--;continue;}
            // force to lower case
            if (s[i] > 'Z') s[i] += k;
            else if (s[j] > 'Z') s[j] += k;
            else if (s[i] != s[j]) return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};
