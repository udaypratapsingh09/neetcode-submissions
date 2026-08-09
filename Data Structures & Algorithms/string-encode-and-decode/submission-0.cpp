class Solution {
public:

    string encode(vector<string>& strs) {
        string coded;
        for (string& str: strs) {
            int len = str.size();
            coded += to_string(len)+"#"+str;
        }
        return coded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        int n = s.size();
        int len = 0;
        while (i<n) {
            // read size
            while (i<n && s[i] != '#') {
                len = len*10 + s[i]-'0';
                i++;
            }
            // skip #
            i++;
            // read string
            decoded.push_back(s.substr(i, len));
            i += len;
            len = 0;
        }
        return decoded;
    }
};
