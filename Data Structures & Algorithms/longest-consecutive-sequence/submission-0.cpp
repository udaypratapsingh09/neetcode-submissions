class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums2(nums.begin(), nums.end());
        int maxLen=0;
        for (auto it:nums2) {
            if (nums2.find(it-1) != nums2.end()) continue;
            int next = it;
            int len = 0;
            while (nums2.find(next) != nums2.end()) {
                next++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
